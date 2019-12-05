using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;          // added to include serial ports
using System.Net;
using System.Net.Sockets;
using System.IO;
using System.Management;

namespace RELAY_MODULE_TEST
{
    public partial class Form1 : Form
    {
        public delegate void AsyncCallback(IAsyncResult ar);
        public delegate void AddTolstDiscoveredDevices(object o);
        enum modules { NONE = 0, USB_RLY08 = 8, USB_RLY16, USB_RLY02, EMPTY, USB_OPTO88, USBOPTO816, EMPTY2, USB_RLY16L, ETHRLY02, ETHRLY16 };
        int module_id = (int)modules.NONE;
        static SerialPort USB_PORT;
        byte[] SerBuf = new byte[10];
        byte serial_written_flag = 0;
        NetworkStream ns;
        TcpClient server;
        private UdpState GlobalUDP;


        struct UdpState
        {
            public System.Net.IPEndPoint EP;
            public System.Net.Sockets.UdpClient UDPClient;
        }

        public Form1()
        {
            InitializeComponent();
            USB_PORT = new SerialPort();
            string[] comportnames = new string[100];
            comportnames = SerialPort.GetPortNames();
            var sortedList = comportnames.OrderBy(port => Convert.ToInt32(port.Replace("COM", string.Empty)));

            foreach (string port in sortedList)
            {
                comboBox_comport.Items.Add(port);                      // places each "COMx" name into combobox
            }

            try
            {
                GlobalUDP.UDPClient = new UdpClient();
                GlobalUDP.EP = new System.Net.IPEndPoint(System.Net.IPAddress.Parse("255.255.255.255"), 30303);
                System.Net.IPEndPoint BindEP = new System.Net.IPEndPoint(System.Net.IPAddress.Any, 30303);
                byte[] DiscoverMsg = Encoding.ASCII.GetBytes("Discovery: Who is out there?");

                // Set the local UDP port to listen on
                GlobalUDP.UDPClient.Client.Bind(BindEP);

                // Enable the transmission of broadcast packets without having them be received by ourself
                GlobalUDP.UDPClient.EnableBroadcast = true;
                GlobalUDP.UDPClient.MulticastLoopback = false;

                // Configure ourself to receive discovery responses
                GlobalUDP.UDPClient.BeginReceive(ReceiveCallback, GlobalUDP);

                // Transmit the discovery request message
                GlobalUDP.UDPClient.Send(DiscoverMsg, DiscoverMsg.Length, new System.Net.IPEndPoint(System.Net.IPAddress.Parse("255.255.255.255"), 30303));
            }
            catch { }
            comboBox_comport.Items.Add("Custom IP");
            comboBox_comport.Text = "Select Port";              // printed only at first execution in the combobox
        }

        public void AddDiscoveryEntry(object o)
        {
            string[] temp;

            temp = ((string)(o)).Split('\n');
            temp[1] = temp[1].TrimEnd(' ');
            if (temp[1] == "ETHRLY16") comboBox_comport.Items.Add(temp[0] + " - " + temp[1]);
            if (temp[1] == "ETHRLY02") comboBox_comport.Items.Add(temp[0] + " - " + temp[1]);
        }

        public void ReceiveCallback(IAsyncResult ar)
        {
            UdpState MyUDP = (UdpState)ar.AsyncState;

            // Obtain the UDP message body and convert it to a string, with remote IP address attached as well
            string ReceiveString = Encoding.ASCII.GetString(MyUDP.UDPClient.EndReceive(ar, ref MyUDP.EP));
            ReceiveString = MyUDP.EP.Address.ToString() + "\n" + ReceiveString.Replace("\r\n", "\n");

            // Configure the UdpClient class to accept more messages, if they arrive
            MyUDP.UDPClient.BeginReceive(ReceiveCallback, MyUDP);
            // Write the received UDP message text to the listbox in a thread-safe manner
            //lstDiscoveredDevices.Invoke(new AddTolstDiscoveredDevices(AddDiscoveryEntry), ReceiveString);
            comboBox_comport.Invoke(new AddTolstDiscoveredDevices(AddDiscoveryEntry), ReceiveString);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            switch (module_id) //module specific code
            {
                case (int)modules.USB_RLY02:
                    if (serial_written_flag != 1) textBox_status.Text = "USB-RLY02 found";
                    visible_components(2, 0, false);    //2 relays, 0 inputs, DC input n/a
                    break;

                case (int)modules.USB_RLY08:
                    textBox_status.Text = "USB-RLY08 found";
                    visible_components(8, 0, false);    //8 relays, 0 inputs, DC input n/a
                    break;

                case (int)modules.USB_RLY16:
                    textBox_status.Text = "USB-RLY16 found";
                    SerBuf[0] = 0x5D;       // get dc voltage command for RLY16
                    transmit(1);
                    receive(1);
                    textBox_dcin.Text = string.Format("{0}v", (float)SerBuf[0] / 10);
                    visible_components(8, 0, true);    //8 relays, 0 inputs, DC input shown
                    break;

                case (int)modules.USB_RLY16L:
                    textBox_status.Text = "USB-RLY16L found";
                    SerBuf[0] = 0x5D;       // get dc voltage command for RLY16
                    transmit(1);
                    receive(1);
                    textBox_dcin.Text = string.Format("{0}v", (float)SerBuf[0] / 10);
                    visible_components(8, 0, true);    //8 relays, 0 inputs, DC input shown
                    break;

                case (int)modules.USB_OPTO88:
                    if (serial_written_flag != 1) textBox_status.Text = "USB-OPTO-RLY88 found";
                    visible_components(8, 8, false);    //8 relays, 8 inputs, DC input n/a
                    get_inputs();
                    break;

                case (int)modules.USBOPTO816:
                    textBox_status.Text = "USB-OPTO-RLY816 found";
                    SerBuf[0] = 0x5D;       // get dc voltage command for RLY16
                    transmit(1);
                    receive(1);
                    textBox_dcin.Text = string.Format("{0}v", (float)SerBuf[0] / 10);
                    visible_components(8, 8, true);    //8 relays, 8 inputs, DC input n/a
                    get_inputs();
                    break;

                case (int)modules.ETHRLY02:
                    if (comboBox_comport.Text == "Custom IP") textBox_status.Text = "ETH-RLY02 found at " + GlobalClass.ipaddress;
                    else textBox_status.Text = "ETH-RLY02 found";
                    visible_components(2, 0, true);    //8 relays, 0 inputs, DC input n/a
                    break;

                case (int)modules.ETHRLY16:
                    if(comboBox_comport.Text == "Custom IP") textBox_status.Text = "ETH-RLY16 found at " + GlobalClass.ipaddress;
                    else textBox_status.Text = "ETH-RLY16 found";
                    visible_components(8, 0, true);    //8 relays, 0 inputs, DC input n/a
                    break;

                default:
                    textBox_status.Text = "Relay module not found";
                    textBox_ver.Text = "";
                    textBox_dcin.Text = "";
                    button_relay1.Text = "RELAY 1";
                    button_relay1.BackColor = Color.White;
                    button_relay2.Text = "RELAY 2";
                    button_relay2.BackColor = Color.White;
                    button_relay3.Text = "RELAY 3";
                    button_relay3.BackColor = Color.White;
                    button_relay4.Text = "RELAY 4";
                    button_relay4.BackColor = Color.White;
                    button_relay5.Text = "RELAY 5";
                    button_relay5.BackColor = Color.White;
                    button_relay6.Text = "RELAY 6";
                    button_relay6.BackColor = Color.White;
                    button_relay7.Text = "RELAY 7";
                    button_relay7.BackColor = Color.White;
                    button_relay8.Text = "RELAY 8";
                    button_relay8.BackColor = Color.White;
                    break;
            }
            if (module_id != (int)modules.NONE)     //if any module is connected then this is the common code
            {
                SerBuf[0] = 0x5B;       // get states command
                transmit(1);
                receive(1);

                if ((SerBuf[0] & 0x01) == 0x01)
                {
                    button_relay1.Text = "RELAY 1 ON";
                    button_relay1.BackColor = Color.Red;
                }
                else
                {
                    button_relay1.Text = "RELAY 1 OFF";
                    button_relay1.BackColor = Color.White;
                }
                if ((SerBuf[0] & 0x02) == 0x02)
                {
                    button_relay2.Text = "RELAY 2 ON";
                    button_relay2.BackColor = Color.Red;
                }
                else
                {
                    button_relay2.Text = "RELAY 2 OFF";
                    button_relay2.BackColor = Color.White;
                }
                if ((SerBuf[0] & 0x04) == 0x04)
                {
                    button_relay3.Text = "RELAY 3 ON";
                    button_relay3.BackColor = Color.Red;
                }
                else
                {
                    button_relay3.Text = "RELAY 3 OFF";
                    button_relay3.BackColor = Color.White;
                }
                if ((SerBuf[0] & 0x08) == 0x08)
                {
                    button_relay4.Text = "RELAY 4 ON";
                    button_relay4.BackColor = Color.Red;
                }
                else
                {
                    button_relay4.Text = "RELAY 4 OFF";
                    button_relay4.BackColor = Color.White;
                }
                if ((SerBuf[0] & 0x10) == 0x10)
                {
                    button_relay5.Text = "RELAY 5 ON";
                    button_relay5.BackColor = Color.Red;
                }
                else
                {
                    button_relay5.Text = "RELAY 5 OFF";
                    button_relay5.BackColor = Color.White;
                }
                if ((SerBuf[0] & 0x20) == 0x20)
                {
                    button_relay6.Text = "RELAY 6 ON";
                    button_relay6.BackColor = Color.Red;
                }
                else
                {
                    button_relay6.Text = "RELAY 6 OFF";
                    button_relay6.BackColor = Color.White;
                }
                if ((SerBuf[0] & 0x40) == 0x40)
                {
                    button_relay7.Text = "RELAY 7 ON";
                    button_relay7.BackColor = Color.Red;
                }
                else
                {
                    button_relay7.Text = "RELAY 7 OFF";
                    button_relay7.BackColor = Color.White;
                }
                if ((SerBuf[0] & 0x80) == 0x80)
                {
                    button_relay8.Text = "RELAY 8 ON";
                    button_relay8.BackColor = Color.Red;
                }
                else
                {
                    button_relay8.Text = "RELAY 8 OFF";
                    button_relay8.BackColor = Color.White;
                }
            }
        }

        private void visible_components(int relays, int inputs, bool volts) // removes or adds applicable components according to selected module
        {
            if (volts == true) textBox_dcin.Visible = label3.Visible = true; //if the module returns an input voltage display label and textbox
            else textBox_dcin.Visible = label3.Visible = false; //else hide 

            if (relays == 8) button_relay1.Visible = button_relay2.Visible = button_relay3.Visible = button_relay4.Visible = button_relay5.Visible = button_relay6.Visible = button_relay7.Visible = button_relay8.Visible = true;
            else
            {
                button_relay1.Visible = button_relay2.Visible = true;
                button_relay3.Visible = button_relay4.Visible = button_relay5.Visible = button_relay6.Visible = button_relay7.Visible = button_relay8.Visible = false;
            }

            if (inputs == 8) radioButton1.Visible = radioButton2.Visible = radioButton3.Visible = radioButton4.Visible = radioButton5.Visible = radioButton6.Visible = radioButton7.Visible = radioButton8.Visible = true;
            else radioButton1.Visible = radioButton2.Visible = radioButton3.Visible = radioButton4.Visible = radioButton5.Visible = radioButton6.Visible = radioButton7.Visible = radioButton8.Visible = false;
        }

        private void get_inputs()   // retrieves opto input states and sets/clears appropiate radio button
        {
            SerBuf[0] = 0x19;       // get input states command
            transmit(1);
            receive(1);
            if ((SerBuf[0] & 0x01) == 0) radioButton1.Checked = false; else radioButton1.Checked = true;
            if ((SerBuf[0] & 0x02) == 0) radioButton2.Checked = false; else radioButton2.Checked = true;
            if ((SerBuf[0] & 0x04) == 0) radioButton3.Checked = false; else radioButton3.Checked = true;
            if ((SerBuf[0] & 0x08) == 0) radioButton4.Checked = false; else radioButton4.Checked = true;
            if ((SerBuf[0] & 0x10) == 0) radioButton5.Checked = false; else radioButton5.Checked = true;
            if ((SerBuf[0] & 0x20) == 0) radioButton6.Checked = false; else radioButton6.Checked = true;
            if ((SerBuf[0] & 0x40) == 0) radioButton7.Checked = false; else radioButton7.Checked = true;
            if ((SerBuf[0] & 0x80) == 0) radioButton8.Checked = false; else radioButton8.Checked = true;
        }

        private void comboBox_comport_SelectedIndexChanged(object sender, EventArgs e)  //opens a comport or network stream corresponding with combobox selection
        {
            module_id = (int)modules.NONE;
            try
            {
                server.Close();
            }
            catch { }

            if (comboBox_comport.Text.StartsWith("COM"))
            {
                if (USB_PORT.IsOpen) USB_PORT.Close();                            // close any existing handle
                USB_PORT.PortName = comboBox_comport.Text;    // retrieves "COMx" from selection in combo box
                USB_PORT.Parity = 0;
                USB_PORT.BaudRate = 19200;
                USB_PORT.StopBits = StopBits.Two;
                USB_PORT.DataBits = 8;
                USB_PORT.ReadTimeout = 50;
                USB_PORT.WriteTimeout = 50;
                USB_PORT.Open();

                SerBuf[0] = 0x5A;       // get version command for RLY16, returns module id and software version
                transmit(1);
                receive(2);

                if (SerBuf[0] != 255)  // if wee recieved the module id  
                {
                    module_id = SerBuf[0];
                    textBox_ver.Text = string.Format("{0}", SerBuf[1]);  //print the software version on screen
                }
            }
            else if (comboBox_comport.Text == "Custom IP")
            {
                Form2 secondForm = new Form2();
                secondForm.ShowDialog();
                if (GlobalClass.ipaddress != "0.0.0.0") open_ethernet_connection();
            }

            else // its an ethernet device selected
            {
                open_ethernet_connection();
            }
        }

        private void open_ethernet_connection() 
        {
               try
                {
                    if (comboBox_comport.Text == "Custom IP")   server = new TcpClient(GlobalClass.ipaddress, GlobalClass.portnumber);
                    else server = new TcpClient(comboBox_comport.Text.Substring(0, comboBox_comport.Text.IndexOf(" ")), 17494);
                    ns = server.GetStream();
                    SerBuf[0] = 0x5A;       // get version command for ETH RLY16, returns software version
                    transmit(1);
                    receive(1);
                    textBox_ver.Text = string.Format("{0}", SerBuf[0]);  //print the software version on screen
                    if (comboBox_comport.Text == "Custom IP") module_id = GlobalClass.module_type;
                    else module_id = (int)modules.ETHRLY16;
                }
                catch (SocketException)
                {
                    if (comboBox_comport.Text == "Custom IP")
                    {
                        MessageBox.Show("Unable to connect to module at " + GlobalClass.ipaddress);
                    }
                    else MessageBox.Show("Unable to connect to module at " + comboBox_comport.Text);
                    return;
                }
        }

        private void transmit(byte write_bytes)
        {
            if (comboBox_comport.Text.StartsWith("COM"))
            {
                try
                {
                    if (USB_PORT.IsOpen) USB_PORT.Write(SerBuf, 0, write_bytes);      // writes specified amount of SerBuf out on COM port
                }
                catch (Exception)
                {
                    USB_PORT.Close();
                    module_id = (int)modules.NONE;
                    MessageBox.Show("write fail");
                }
            }
            else // its an ethernet device selected
            {
                try
                {
                    ns.Write(SerBuf, 0, write_bytes);
                    ns.Flush();
                }
                catch
                {
                    module_id = (int)modules.NONE;
                    MessageBox.Show("write fail");
                }
            }
        }

        private void receive(byte read_bytes)
        {
            byte x;

            if (comboBox_comport.Text.StartsWith("COM"))
            {
                for (x = 0; x < read_bytes && USB_PORT.IsOpen; x++)       // this will call the read function for the passed number times, 
                {                                      // this way it ensures each byte has been correctly recieved while
                    try                                // still using timeouts
                    {
                        USB_PORT.Read(SerBuf, x, 1);     // retrieves 1 byte at a time and places in SerBuf at position x
                    }
                    catch (Exception)                   // timeout or other error occured, set lost comms indicator
                    {
                        USB_PORT.Close();
                        SerBuf[0] = 255;
                        MessageBox.Show("read fail");
                        module_id = (int)modules.NONE;
                    }
                }
            }
            else // its an ethernet device selected
            {
                for (x = 0; x < read_bytes; x++)       // this will call the read function for the passed number times, 
                {                                      // this way it ensures each byte has been correctly recieved while
                    try                                // still using timeouts
                    {
                        ns.Read(SerBuf, x, 1);     // retrieves 1 byte at a time and places in SerBuf at position x
                    }
                    catch (Exception)                   // timeout or other error occured, set lost comms indicator
                    {
                        module_id = (int)modules.NONE;
                        MessageBox.Show("read fail");
                    }
                }
            }
        }

        private void button_relay1_Click(object sender, EventArgs e)
        {
            if (module_id != (int)modules.NONE)
            {
                if (button_relay1.Text == "RELAY 1 ON") SerBuf[0] = 0x6F;
                else SerBuf[0] = 0x65;
                transmit(1);
            }
        }

        private void button_relay2_Click(object sender, EventArgs e)
        {
            if (module_id != (int)modules.NONE)
            {
                if (button_relay2.Text == "RELAY 2 ON") SerBuf[0] = 0x70;
                else SerBuf[0] = 0x66;
                transmit(1);
            }
        }

        private void button_relay3_Click(object sender, EventArgs e)
        {
            if (module_id != (int)modules.NONE)
            {
                if (button_relay3.Text == "RELAY 3 ON") SerBuf[0] = 0x71;
                else SerBuf[0] = 0x67;
                transmit(1);
            }
        }

        private void button_relay4_Click(object sender, EventArgs e)
        {
            if (module_id != (int)modules.NONE)
            {
                if (button_relay4.Text == "RELAY 4 ON") SerBuf[0] = 0x72;
                else SerBuf[0] = 0x68;
                transmit(1);
            }
        }

        private void button_relay5_Click(object sender, EventArgs e)
        {
            if (module_id != (int)modules.NONE)
            {
                if (button_relay5.Text == "RELAY 5 ON") SerBuf[0] = 0x73;
                else SerBuf[0] = 0x69;
                transmit(1);
            }
        }

        private void button_relay6_Click(object sender, EventArgs e)
        {
            if (module_id != (int)modules.NONE)
            {
                if (button_relay6.Text == "RELAY 6 ON") SerBuf[0] = 0x74;
                else SerBuf[0] = 0x6A;
                transmit(1);
            }
        }

        private void button_relay7_Click(object sender, EventArgs e)
        {
            if (module_id != (int)modules.NONE)
            {
                if (button_relay7.Text == "RELAY 7 ON") SerBuf[0] = 0x75;
                else SerBuf[0] = 0x6B;
                transmit(1);
            }
        }

        private void button_relay8_Click(object sender, EventArgs e)
        {
            if (module_id != (int)modules.NONE)
            {
                if (button_relay8.Text == "RELAY 8 ON") SerBuf[0] = 0x76;
                else SerBuf[0] = 0x6C;
                transmit(1);
            }
        }

        private void button_allon_Click(object sender, EventArgs e)
        {
            if (module_id != (int)modules.NONE)
            {
                SerBuf[0] = 0x64;
                transmit(1);
            }
        }

        private void button_alloff_Click(object sender, EventArgs e)
        {
            if (module_id != (int)modules.NONE)
            {
                SerBuf[0] = 0x6E;
                transmit(1);
            }
        }

        private void button_01010101_Click(object sender, EventArgs e)
        {
            if (module_id != (int)modules.NONE)
            {
                SerBuf[0] = 0x5C;
                SerBuf[1] = 0x55;
                transmit(2);
            }
        }

        private void button10101010_Click(object sender, EventArgs e)
        {
            if (module_id != (int)modules.NONE)
            {
                SerBuf[0] = 0x5c;
                SerBuf[1] = 0xAA;
                transmit(2);
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e) // attempt to close any open network stream on form closure
        {
            try
            {
                ns.Close();
                ns.Dispose();
                server.Close();
            }
            catch { }
        }
    }
}
