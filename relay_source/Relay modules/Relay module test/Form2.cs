using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;

namespace RELAY_MODULE_TEST
{
    enum modules { NONE = 0, USB_RLY08 = 8, USB_RLY16, USB_RLY02, EMPTY, USB_OPTO88, USBOPTO816, EMPTY2, USB_RLY16L, ETHRLY02, ETHRLY16 };

    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
            GlobalClass.ipaddress = ("0.0.0.0");
            comboBox_boardtype.Items.Add("ETHRLY02");
            comboBox_boardtype.Items.Add("ETHRLY16");
            comboBox_boardtype.SelectedIndex = 0;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void textBox_KeyPress(object sender, KeyPressEventArgs e)
        {
            switch (e.KeyChar.ToString())
            {
                case "0": break;
                case "1": break;
                case "2": break;
                case "3": break;
                case "4": break;
                case "5": break;
                case "6": break;
                case "7": break;
                case "8": break;
                case "9": break;
                case "\b": break; //delete  
                default: e.Handled = true;
                    break;
            }
        }

             private void button1_Click(object sender, EventArgs e)
             {
                 if (IsAddressValid(textBoxIP1.Text + '.' + textBoxIP2.Text + '.' + textBoxIP3.Text + '.' + textBoxIP4.Text) == true)
                 {
                     GlobalClass.ipaddress = textBoxIP1.Text + '.' + textBoxIP2.Text + '.' + textBoxIP3.Text + '.' + textBoxIP4.Text;
                     GlobalClass.portnumber = (int) numericUpDown_port.Value;
                     if (comboBox_boardtype.Text == "ETHRLY02") GlobalClass.module_type = (byte) modules.ETHRLY02;
                     else GlobalClass.module_type = (byte) modules.ETHRLY16;
                     Close();
                 }
                 else {
                     MessageBox.Show("INVALID IP ADDRESS","ERROR");
                 }
             }

             public bool IsAddressValid(string addrString)
             {
                 IPAddress address;
                 return IPAddress.TryParse(addrString, out address);
             }
    }
}
