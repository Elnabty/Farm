namespace RELAY_MODULE_TEST
{
    partial class Form2
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
            this.button1 = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.textBoxIP4 = new System.Windows.Forms.TextBox();
            this.textBoxIP3 = new System.Windows.Forms.TextBox();
            this.textBoxIP2 = new System.Windows.Forms.TextBox();
            this.textBoxIP1 = new System.Windows.Forms.TextBox();
            this.comboBox_boardtype = new System.Windows.Forms.ComboBox();
            this.numericUpDown_port = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_port)).BeginInit();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(85, 110);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 38;
            this.button1.Text = "TRY IP";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(12, 9);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(148, 13);
            this.label4.TabIndex = 37;
            this.label4.Text = "ENTER CUSTOM IP BELOW";
            // 
            // textBoxIP4
            // 
            this.textBoxIP4.Location = new System.Drawing.Point(128, 25);
            this.textBoxIP4.MaxLength = 3;
            this.textBoxIP4.Name = "textBoxIP4";
            this.textBoxIP4.Size = new System.Drawing.Size(32, 20);
            this.textBoxIP4.TabIndex = 36;
            this.textBoxIP4.Text = "0";
            this.textBoxIP4.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBox_KeyPress);
            // 
            // textBoxIP3
            // 
            this.textBoxIP3.Location = new System.Drawing.Point(90, 25);
            this.textBoxIP3.MaxLength = 3;
            this.textBoxIP3.Name = "textBoxIP3";
            this.textBoxIP3.Size = new System.Drawing.Size(32, 20);
            this.textBoxIP3.TabIndex = 35;
            this.textBoxIP3.Text = "0";
            this.textBoxIP3.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBox_KeyPress);
            // 
            // textBoxIP2
            // 
            this.textBoxIP2.Location = new System.Drawing.Point(52, 25);
            this.textBoxIP2.MaxLength = 3;
            this.textBoxIP2.Name = "textBoxIP2";
            this.textBoxIP2.Size = new System.Drawing.Size(32, 20);
            this.textBoxIP2.TabIndex = 34;
            this.textBoxIP2.Text = "0";
            this.textBoxIP2.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBox_KeyPress);
            // 
            // textBoxIP1
            // 
            this.textBoxIP1.Location = new System.Drawing.Point(15, 25);
            this.textBoxIP1.MaxLength = 3;
            this.textBoxIP1.Name = "textBoxIP1";
            this.textBoxIP1.Size = new System.Drawing.Size(32, 20);
            this.textBoxIP1.TabIndex = 33;
            this.textBoxIP1.Text = "0";
            this.textBoxIP1.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBox_KeyPress);
            // 
            // comboBox_boardtype
            // 
            this.comboBox_boardtype.FormattingEnabled = true;
            this.comboBox_boardtype.Location = new System.Drawing.Point(15, 51);
            this.comboBox_boardtype.Name = "comboBox_boardtype";
            this.comboBox_boardtype.Size = new System.Drawing.Size(145, 21);
            this.comboBox_boardtype.TabIndex = 39;
            // 
            // numericUpDown_port
            // 
            this.numericUpDown_port.Location = new System.Drawing.Point(85, 84);
            this.numericUpDown_port.Maximum = new decimal(new int[] {
            20000,
            0,
            0,
            0});
            this.numericUpDown_port.Name = "numericUpDown_port";
            this.numericUpDown_port.Size = new System.Drawing.Size(75, 20);
            this.numericUpDown_port.TabIndex = 40;
            this.numericUpDown_port.Value = new decimal(new int[] {
            17494,
            0,
            0,
            0});
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(53, 86);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(26, 13);
            this.label1.TabIndex = 41;
            this.label1.Text = "Port";
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(204, 145);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.numericUpDown_port);
            this.Controls.Add(this.comboBox_boardtype);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.textBoxIP4);
            this.Controls.Add(this.textBoxIP3);
            this.Controls.Add(this.textBoxIP2);
            this.Controls.Add(this.textBoxIP1);
            this.Name = "Form2";
            this.Text = "Enter IP address";
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown_port)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textBoxIP4;
        private System.Windows.Forms.TextBox textBoxIP3;
        private System.Windows.Forms.TextBox textBoxIP2;
        private System.Windows.Forms.TextBox textBoxIP1;
        private System.Windows.Forms.ComboBox comboBox_boardtype;
        private System.Windows.Forms.NumericUpDown numericUpDown_port;
        private System.Windows.Forms.Label label1;
    }
}