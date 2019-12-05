namespace RELAY_MODULE_TEST
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.comboBox_comport = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.textBox_ver = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.button_relay1 = new System.Windows.Forms.Button();
            this.button_relay2 = new System.Windows.Forms.Button();
            this.button_relay3 = new System.Windows.Forms.Button();
            this.button_relay4 = new System.Windows.Forms.Button();
            this.button_relay5 = new System.Windows.Forms.Button();
            this.button_relay6 = new System.Windows.Forms.Button();
            this.button_relay7 = new System.Windows.Forms.Button();
            this.button_relay8 = new System.Windows.Forms.Button();
            this.button_allon = new System.Windows.Forms.Button();
            this.button_alloff = new System.Windows.Forms.Button();
            this.button_01010101 = new System.Windows.Forms.Button();
            this.button10101010 = new System.Windows.Forms.Button();
            this.textBox_dcin = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textBox_status = new System.Windows.Forms.TextBox();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton3 = new System.Windows.Forms.RadioButton();
            this.radioButton4 = new System.Windows.Forms.RadioButton();
            this.radioButton5 = new System.Windows.Forms.RadioButton();
            this.radioButton6 = new System.Windows.Forms.RadioButton();
            this.radioButton7 = new System.Windows.Forms.RadioButton();
            this.radioButton8 = new System.Windows.Forms.RadioButton();
            this.SuspendLayout();
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // comboBox_comport
            // 
            this.comboBox_comport.FormattingEnabled = true;
            this.comboBox_comport.Location = new System.Drawing.Point(204, 7);
            this.comboBox_comport.Name = "comboBox_comport";
            this.comboBox_comport.Size = new System.Drawing.Size(149, 21);
            this.comboBox_comport.TabIndex = 0;
            this.comboBox_comport.SelectedIndexChanged += new System.EventHandler(this.comboBox_comport_SelectedIndexChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(158, 10);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(40, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = " PORT";
            // 
            // textBox_ver
            // 
            this.textBox_ver.Location = new System.Drawing.Point(326, 35);
            this.textBox_ver.Name = "textBox_ver";
            this.textBox_ver.Size = new System.Drawing.Size(27, 20);
            this.textBox_ver.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(265, 38);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(55, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "VERSION";
            // 
            // button_relay1
            // 
            this.button_relay1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button_relay1.Location = new System.Drawing.Point(3, 5);
            this.button_relay1.Name = "button_relay1";
            this.button_relay1.Size = new System.Drawing.Size(64, 23);
            this.button_relay1.TabIndex = 4;
            this.button_relay1.Text = "RELAY 1";
            this.button_relay1.UseVisualStyleBackColor = true;
            this.button_relay1.Click += new System.EventHandler(this.button_relay1_Click);
            // 
            // button_relay2
            // 
            this.button_relay2.Location = new System.Drawing.Point(3, 32);
            this.button_relay2.Name = "button_relay2";
            this.button_relay2.Size = new System.Drawing.Size(64, 23);
            this.button_relay2.TabIndex = 5;
            this.button_relay2.Text = "RELAY 2";
            this.button_relay2.UseVisualStyleBackColor = true;
            this.button_relay2.Click += new System.EventHandler(this.button_relay2_Click);
            // 
            // button_relay3
            // 
            this.button_relay3.Location = new System.Drawing.Point(3, 61);
            this.button_relay3.Name = "button_relay3";
            this.button_relay3.Size = new System.Drawing.Size(64, 23);
            this.button_relay3.TabIndex = 6;
            this.button_relay3.Text = "RELAY 3";
            this.button_relay3.UseVisualStyleBackColor = true;
            this.button_relay3.Click += new System.EventHandler(this.button_relay3_Click);
            // 
            // button_relay4
            // 
            this.button_relay4.Location = new System.Drawing.Point(3, 90);
            this.button_relay4.Name = "button_relay4";
            this.button_relay4.Size = new System.Drawing.Size(64, 23);
            this.button_relay4.TabIndex = 7;
            this.button_relay4.Text = "RELAY 4";
            this.button_relay4.UseVisualStyleBackColor = true;
            this.button_relay4.Click += new System.EventHandler(this.button_relay4_Click);
            // 
            // button_relay5
            // 
            this.button_relay5.Location = new System.Drawing.Point(3, 119);
            this.button_relay5.Name = "button_relay5";
            this.button_relay5.Size = new System.Drawing.Size(64, 23);
            this.button_relay5.TabIndex = 8;
            this.button_relay5.Text = "RELAY 5";
            this.button_relay5.UseVisualStyleBackColor = true;
            this.button_relay5.Click += new System.EventHandler(this.button_relay5_Click);
            // 
            // button_relay6
            // 
            this.button_relay6.Location = new System.Drawing.Point(3, 148);
            this.button_relay6.Name = "button_relay6";
            this.button_relay6.Size = new System.Drawing.Size(64, 23);
            this.button_relay6.TabIndex = 9;
            this.button_relay6.Text = "RELAY 6";
            this.button_relay6.UseVisualStyleBackColor = true;
            this.button_relay6.Click += new System.EventHandler(this.button_relay6_Click);
            // 
            // button_relay7
            // 
            this.button_relay7.Location = new System.Drawing.Point(3, 177);
            this.button_relay7.Name = "button_relay7";
            this.button_relay7.Size = new System.Drawing.Size(64, 23);
            this.button_relay7.TabIndex = 10;
            this.button_relay7.Text = "RELAY 7";
            this.button_relay7.UseVisualStyleBackColor = true;
            this.button_relay7.Click += new System.EventHandler(this.button_relay7_Click);
            // 
            // button_relay8
            // 
            this.button_relay8.Location = new System.Drawing.Point(3, 206);
            this.button_relay8.Name = "button_relay8";
            this.button_relay8.Size = new System.Drawing.Size(64, 23);
            this.button_relay8.TabIndex = 11;
            this.button_relay8.Text = "RELAY 8";
            this.button_relay8.UseVisualStyleBackColor = true;
            this.button_relay8.Click += new System.EventHandler(this.button_relay8_Click);
            // 
            // button_allon
            // 
            this.button_allon.Location = new System.Drawing.Point(246, 146);
            this.button_allon.Name = "button_allon";
            this.button_allon.Size = new System.Drawing.Size(64, 23);
            this.button_allon.TabIndex = 12;
            this.button_allon.Text = "ALL ON";
            this.button_allon.UseVisualStyleBackColor = true;
            this.button_allon.Click += new System.EventHandler(this.button_allon_Click);
            // 
            // button_alloff
            // 
            this.button_alloff.Location = new System.Drawing.Point(176, 146);
            this.button_alloff.Name = "button_alloff";
            this.button_alloff.Size = new System.Drawing.Size(64, 23);
            this.button_alloff.TabIndex = 13;
            this.button_alloff.Text = "ALL OFF";
            this.button_alloff.UseVisualStyleBackColor = true;
            this.button_alloff.Click += new System.EventHandler(this.button_alloff_Click);
            // 
            // button_01010101
            // 
            this.button_01010101.Location = new System.Drawing.Point(176, 175);
            this.button_01010101.Name = "button_01010101";
            this.button_01010101.Size = new System.Drawing.Size(64, 23);
            this.button_01010101.TabIndex = 14;
            this.button_01010101.Text = "01010101";
            this.button_01010101.UseVisualStyleBackColor = true;
            this.button_01010101.Click += new System.EventHandler(this.button_01010101_Click);
            // 
            // button10101010
            // 
            this.button10101010.Location = new System.Drawing.Point(246, 175);
            this.button10101010.Name = "button10101010";
            this.button10101010.Size = new System.Drawing.Size(64, 23);
            this.button10101010.TabIndex = 15;
            this.button10101010.Text = "10101010";
            this.button10101010.UseVisualStyleBackColor = true;
            this.button10101010.Click += new System.EventHandler(this.button10101010_Click);
            // 
            // textBox_dcin
            // 
            this.textBox_dcin.Location = new System.Drawing.Point(296, 64);
            this.textBox_dcin.Name = "textBox_dcin";
            this.textBox_dcin.Size = new System.Drawing.Size(57, 20);
            this.textBox_dcin.TabIndex = 16;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(254, 67);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(36, 13);
            this.label3.TabIndex = 17;
            this.label3.Text = "DC IN";
            // 
            // textBox_status
            // 
            this.textBox_status.Location = new System.Drawing.Point(173, 204);
            this.textBox_status.Name = "textBox_status";
            this.textBox_status.Size = new System.Drawing.Size(180, 20);
            this.textBox_status.TabIndex = 18;
            // 
            // radioButton1
            // 
            this.radioButton1.AutoCheck = false;
            this.radioButton1.AutoSize = true;
            this.radioButton1.ForeColor = System.Drawing.SystemColors.ControlText;
            this.radioButton1.Location = new System.Drawing.Point(83, 8);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(45, 17);
            this.radioButton1.TabIndex = 19;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "inp1";
            this.radioButton1.UseVisualStyleBackColor = true;
            this.radioButton1.Visible = false;
            // 
            // radioButton2
            // 
            this.radioButton2.AutoCheck = false;
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(83, 35);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(45, 17);
            this.radioButton2.TabIndex = 20;
            this.radioButton2.TabStop = true;
            this.radioButton2.Text = "inp2";
            this.radioButton2.UseVisualStyleBackColor = true;
            this.radioButton2.Visible = false;
            // 
            // radioButton3
            // 
            this.radioButton3.AutoCheck = false;
            this.radioButton3.AutoSize = true;
            this.radioButton3.Location = new System.Drawing.Point(83, 64);
            this.radioButton3.Name = "radioButton3";
            this.radioButton3.Size = new System.Drawing.Size(45, 17);
            this.radioButton3.TabIndex = 21;
            this.radioButton3.TabStop = true;
            this.radioButton3.Text = "inp3";
            this.radioButton3.UseVisualStyleBackColor = true;
            this.radioButton3.Visible = false;
            // 
            // radioButton4
            // 
            this.radioButton4.AutoCheck = false;
            this.radioButton4.AutoSize = true;
            this.radioButton4.Location = new System.Drawing.Point(83, 93);
            this.radioButton4.Name = "radioButton4";
            this.radioButton4.Size = new System.Drawing.Size(45, 17);
            this.radioButton4.TabIndex = 22;
            this.radioButton4.TabStop = true;
            this.radioButton4.Text = "inp4";
            this.radioButton4.UseVisualStyleBackColor = true;
            this.radioButton4.Visible = false;
            // 
            // radioButton5
            // 
            this.radioButton5.AutoCheck = false;
            this.radioButton5.AutoSize = true;
            this.radioButton5.Location = new System.Drawing.Point(83, 122);
            this.radioButton5.Name = "radioButton5";
            this.radioButton5.Size = new System.Drawing.Size(45, 17);
            this.radioButton5.TabIndex = 23;
            this.radioButton5.TabStop = true;
            this.radioButton5.Text = "inp5";
            this.radioButton5.UseVisualStyleBackColor = true;
            this.radioButton5.Visible = false;
            // 
            // radioButton6
            // 
            this.radioButton6.AutoCheck = false;
            this.radioButton6.AutoSize = true;
            this.radioButton6.Location = new System.Drawing.Point(83, 151);
            this.radioButton6.Name = "radioButton6";
            this.radioButton6.Size = new System.Drawing.Size(45, 17);
            this.radioButton6.TabIndex = 24;
            this.radioButton6.TabStop = true;
            this.radioButton6.Text = "inp6";
            this.radioButton6.UseVisualStyleBackColor = true;
            this.radioButton6.Visible = false;
            // 
            // radioButton7
            // 
            this.radioButton7.AutoCheck = false;
            this.radioButton7.AutoSize = true;
            this.radioButton7.Location = new System.Drawing.Point(83, 180);
            this.radioButton7.Name = "radioButton7";
            this.radioButton7.Size = new System.Drawing.Size(45, 17);
            this.radioButton7.TabIndex = 25;
            this.radioButton7.TabStop = true;
            this.radioButton7.Text = "inp7";
            this.radioButton7.UseVisualStyleBackColor = true;
            this.radioButton7.Visible = false;
            // 
            // radioButton8
            // 
            this.radioButton8.AutoCheck = false;
            this.radioButton8.AutoSize = true;
            this.radioButton8.Location = new System.Drawing.Point(83, 209);
            this.radioButton8.Name = "radioButton8";
            this.radioButton8.Size = new System.Drawing.Size(45, 17);
            this.radioButton8.TabIndex = 26;
            this.radioButton8.TabStop = true;
            this.radioButton8.Text = "inp8";
            this.radioButton8.UseVisualStyleBackColor = true;
            this.radioButton8.Visible = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(356, 232);
            this.Controls.Add(this.radioButton8);
            this.Controls.Add(this.radioButton7);
            this.Controls.Add(this.radioButton6);
            this.Controls.Add(this.radioButton5);
            this.Controls.Add(this.radioButton4);
            this.Controls.Add(this.radioButton3);
            this.Controls.Add(this.radioButton2);
            this.Controls.Add(this.radioButton1);
            this.Controls.Add(this.textBox_status);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textBox_dcin);
            this.Controls.Add(this.button10101010);
            this.Controls.Add(this.button_01010101);
            this.Controls.Add(this.button_alloff);
            this.Controls.Add(this.button_allon);
            this.Controls.Add(this.button_relay8);
            this.Controls.Add(this.button_relay7);
            this.Controls.Add(this.button_relay6);
            this.Controls.Add(this.button_relay5);
            this.Controls.Add(this.button_relay4);
            this.Controls.Add(this.button_relay3);
            this.Controls.Add(this.button_relay2);
            this.Controls.Add(this.button_relay1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBox_ver);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.comboBox_comport);
            this.Name = "Form1";
            this.Text = "Relay module test";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.ComboBox comboBox_comport;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBox_ver;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button button_relay1;
        private System.Windows.Forms.Button button_relay2;
        private System.Windows.Forms.Button button_relay3;
        private System.Windows.Forms.Button button_relay4;
        private System.Windows.Forms.Button button_relay5;
        private System.Windows.Forms.Button button_relay6;
        private System.Windows.Forms.Button button_relay7;
        private System.Windows.Forms.Button button_relay8;
        private System.Windows.Forms.Button button_allon;
        private System.Windows.Forms.Button button_alloff;
        private System.Windows.Forms.Button button_01010101;
        private System.Windows.Forms.Button button10101010;
        private System.Windows.Forms.TextBox textBox_dcin;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBox_status;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton radioButton3;
        private System.Windows.Forms.RadioButton radioButton4;
        private System.Windows.Forms.RadioButton radioButton5;
        private System.Windows.Forms.RadioButton radioButton6;
        private System.Windows.Forms.RadioButton radioButton7;
        private System.Windows.Forms.RadioButton radioButton8;
    }
}

