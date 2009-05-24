using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace TextBoxTest
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.buttonOK.Enabled = false;

            this.textBoxAddress.Tag = false;
            this.textBoxAge.Tag = false;
            this.textBoxName.Tag = false;

            this.textBoxName.Validating += new System.ComponentModel.
                CancelEventHandler(this.textBoxEmpty_Validating);

            this.textBoxAddress.Validating += new
            System.ComponentModel.CancelEventHandler(this.textBoxEmpty_Validating);

            this.textBoxAge.Validating += new
            System.ComponentModel.CancelEventHandler(this.textBoxEmpty_Validating);
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string output;

            output = "Name: " + this.textBoxName.Text + "\r\n";
            output += "Address: " + this.textBoxAddress.Text + "\r\n";
            output += "Occupation: " + (string)(this.checkBoxProgrammer.Checked ?
                "Programmer" : "Not a programmer") + "\r\n";
            output += "Sex: " + (string)(this.radioButtonFemale.Checked ?
                "Female" : "Male") + "\r\n";
            output += "Age: " + this.textBoxAge.Text + "\r\n";

            this.textBoxOutput.Text = output;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string output;

            output = "Name = Your name\r\n";
            output += "Address = Your Address\r\n";
            output += "Programmer = Check 'Programmer' if you are a programmer\r\n";
            output += "Sex = Choose your sex\r\n";
            output += "Age = Your age";

            this.textBoxOutput.Text = output;
        }

        private void textBoxEmpty_Validating(object sender,
            System.ComponentModel.CancelEventArgs e)
        {
            TextBox tb = (TextBox)sender;

            if (tb.Text.Length == 0)
            {
                tb.BackColor = Color.Red;
                tb.Tag = false;
            }
            else
            {
                tb.BackColor = System.Drawing.SystemColors.Window;
                tb.Tag = true;
            }

            ValidateOK();
        }

        private void ValidateOK()
        {
            this.buttonOK.Enabled = ((bool)(this.textBoxAddress.Tag) &&
                                                        (bool)(this.textBoxAge.Tag) &&
                                                        (bool)(this.textBoxName.Tag));
        }

        private void textBoxAge_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((e.KeyChar < 48 || e.KeyChar > 57) && e.KeyChar != 8)
                e.Handled = true;
        }

        private void textBox_TextChanged(object sender, EventArgs e)
        {
            TextBox tb = (TextBox)sender;

            if (tb.Text.Length == 0)
            {
                tb.Tag = false;
                tb.BackColor = Color.Red;
            }
            else
            {
                tb.Tag = true;
                tb.BackColor = SystemColors.Window;
            }

            ValidateOK();
        }
    }
}