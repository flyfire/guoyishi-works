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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            this.toolStripComboBoxFonts.SelectedIndex = 0;
        }

        private void MenuItemShowHelpItem_CheckedChanged(object sender, EventArgs e)
        {
            ToolStripMenuItem item = (ToolStripMenuItem)sender;
            MenuItemHelp.Visible = item.Checked;
        }

        private void MenuItemNew_Click(object sender, EventArgs e)
        {
            this.richTextBoxText.Text = "";
        }

        private void MenuItemOpen_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            if (ofd.ShowDialog() == DialogResult.OK)
            {
                this.richTextBoxText.LoadFile(ofd.FileName.ToString());
            }
        }

        private void MenuItemSave_Click(object sender, EventArgs e)
        {
            SaveFileDialog sfd = new SaveFileDialog();
            if (sfd.ShowDialog() == DialogResult.OK)
            {
                this.richTextBoxText.SaveFile(sfd.FileName.ToString());
            }
        }
    }
}
