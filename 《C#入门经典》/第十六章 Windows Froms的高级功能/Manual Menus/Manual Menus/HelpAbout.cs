using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Manual_Menus
{
    public partial class HelpAbout : Form
    {
        public HelpAbout()
        {
            InitializeComponent();
            printTextBox();
        }

        private void printTextBox()
        {
            string str = "";
            str += "meiyou.org\n";
            str += "CUST\n";

            this.textBoxAbout.Text = str;
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }
    }
}
