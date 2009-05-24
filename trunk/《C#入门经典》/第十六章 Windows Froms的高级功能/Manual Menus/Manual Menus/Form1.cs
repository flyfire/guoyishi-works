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
    public partial class frmEditor : Form
    {
        public frmEditor(frmContainer parent, int counter)
        {
            InitializeComponent();

            this.toolStripComboBoxFonts.SelectedIndex = 0;

            this.MdiParent = parent;
            this.Text = "Editor: " + counter.ToString();
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

        private void toolStripButtonBold_CheckedChanged(object sender, EventArgs e)
        {
            Font oldFont;
            Font newFont;

            bool checkState = ((ToolStripButton)sender).Checked;

            oldFont = this.richTextBoxText.SelectionFont;

            if (!checkState)
            {
                newFont = new Font(oldFont, oldFont.Style & ~FontStyle.Bold);
            }
            else
            {
                newFont = new Font(oldFont, oldFont.Style | FontStyle.Bold);
            }

            this.richTextBoxText.SelectionFont = newFont;
            this.richTextBoxText.Focus();

            this.ToolStripMenuItemBold.CheckedChanged -= new
                EventHandler(ToolStripMenuItemBold_CheckedChanged);
            this.ToolStripMenuItemBold.Checked = checkState;
            this.ToolStripMenuItemBold.CheckedChanged += new
                EventHandler(ToolStripMenuItemBold_CheckedChanged);

            this.toolStripStatusLabelBold.Enabled = checkState;
        }

        private void ToolStripMenuItemBold_CheckedChanged(object sender, EventArgs e)
        {
            this.toolStripButtonBold.Checked = ToolStripMenuItemBold.Checked;
        }

        private void ToolStripMenuItemItalic_CheckedChanged(object sender, EventArgs e)
        {
            this.toolStripButtonItalic.Checked = ToolStripMenuItemItalic.Checked;
        }

        private void ToolStripMenuItemUnderline_CheckedChanged(object sender, EventArgs e)
        {
            this.toolStripButtonUnderline.Checked = ToolStripMenuItemUnderline.Checked;
        }

        private void toolStripButtonItalic_CheckedChanged(object sender, EventArgs e)
        {
            Font oldFont;
            Font newFont;

            bool checkState = ((ToolStripButton)sender).Checked;

            oldFont = this.richTextBoxText.SelectionFont;

            if (!checkState)
                newFont = new Font(oldFont, oldFont.Style & ~FontStyle.Italic);
            else
                newFont = new Font(oldFont, oldFont.Style | FontStyle.Italic);

            this.richTextBoxText.SelectionFont = newFont;
            this.richTextBoxText.Focus();

            this.ToolStripMenuItemItalic.CheckedChanged -= new
                EventHandler(ToolStripMenuItemItalic_CheckedChanged);
            this.ToolStripMenuItemItalic.Checked = checkState;
            this.ToolStripMenuItemItalic.CheckedChanged += new
                EventHandler(ToolStripMenuItemItalic_CheckedChanged);

            this.toolStripStatusLabelItalic.Enabled = checkState;
        }

        private void toolStripButtonUnderline_CheckedChanged(object sender, EventArgs e)
        {
            Font oldFont;
            Font newFont;

            bool checkState = ((ToolStripButton)sender).Checked;

            oldFont = this.richTextBoxText.SelectionFont;

            if (!checkState)
                newFont = new Font(oldFont, oldFont.Style & ~FontStyle.Underline);
            else
                newFont = new Font(oldFont, oldFont.Style | FontStyle.Underline);

            this.richTextBoxText.SelectionFont = newFont;
            this.richTextBoxText.Focus();

            this.ToolStripMenuItemUnderline.CheckedChanged -= new
                EventHandler(ToolStripMenuItemUnderline_CheckedChanged);
            this.ToolStripMenuItemUnderline.Checked = checkState;
            this.ToolStripMenuItemUnderline.CheckedChanged += new
                EventHandler(ToolStripMenuItemUnderline_CheckedChanged);

            this.toolStripStatusLabelUnderline.Enabled = checkState;
        }

        private void toolStripComboBoxFonts_SelectedIndexChanged(object sender, EventArgs e)
        {
            string text = ((ToolStripComboBox)sender).SelectedItem.ToString();
            Font newFont = null;

            if (richTextBoxText.SelectionFont == null)
                newFont = new Font(text, richTextBoxText.Font.Size);
            else
                newFont = new Font(text, richTextBoxText.SelectionFont.Size,
                    richTextBoxText.SelectionFont.Style);

            this.richTextBoxText.SelectionFont = newFont;
        }

        private void richTextBoxText_TextChanged(object sender, EventArgs e)
        {
            this.toolStripStatusLabelText.Text = "Number of characters: " +
                richTextBoxText.Text.Length;
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            HelpAbout newAbout = new HelpAbout();
            newAbout.Show();

        }


    }
}
