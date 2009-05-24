using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace RichTextBoxTest
{
    public partial class RichTextBoxTest : Form
    {
        public RichTextBoxTest()
        {
            InitializeComponent();
        }

        private void buttonBold_Click(object sender, EventArgs e)
        {
            Font oldFont;
            Font newFont;

            oldFont = this.richTextBoxText.SelectionFont;
            if (oldFont.Bold)
            {
                newFont = new Font(oldFont, oldFont.Style & ~FontStyle.Bold);
            }
            else
                newFont = new Font(oldFont, oldFont.Style | FontStyle.Bold);

            this.richTextBoxText.SelectionFont = newFont;
            this.richTextBoxText.Focus();
        }

        private void buttonUnderline_Click(object sender, EventArgs e)
        {
            Font oldFont;
            Font newFont;

            oldFont = this.richTextBoxText.SelectionFont;
            if (oldFont.Underline)
                newFont = new Font(oldFont, oldFont.Style & ~FontStyle.Underline);
            else
                newFont = new Font(oldFont, oldFont.Style | FontStyle.Underline);

            this.richTextBoxText.SelectionFont = newFont;
            this.richTextBoxText.Focus();
        }

        private void buttonItalic_Click(object sender, EventArgs e)
        {
            Font oldFont;
            Font newFont;

            oldFont = this.richTextBoxText.SelectionFont;
            if (oldFont.Italic)
                newFont = new Font(oldFont, oldFont.Style & ~FontStyle.Italic);
            else
                newFont = new Font(oldFont, oldFont.Style | FontStyle.Italic);

            this.richTextBoxText.SelectionFont = newFont;
            this.richTextBoxText.Focus();
        }

        private void buttonCenter_Click(object sender, EventArgs e)
        {
            if (this.richTextBoxText.SelectionAlignment == HorizontalAlignment.Center)
                this.richTextBoxText.SelectionAlignment = HorizontalAlignment.Left;
            else
                this.richTextBoxText.SelectionAlignment = HorizontalAlignment.Center;

            this.richTextBoxText.Focus();
        }

        private void textBoxSize_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((e.KeyChar < 48 || e.KeyChar > 57) &&
                e.KeyChar != 8 && e.KeyChar != 13)
            {
                e.Handled = true;
            }
            else if (e.KeyChar == 13)
            {
                TextBox txt = (TextBox)sender;
                if (txt.Text.Length > 0)
                    ApplyTextSize(txt.Text);
                e.Handled = true;
                this.richTextBoxText.Focus();
            }
        }

        private void textBoxSize_Validated(object sender, EventArgs e)
        {
            TextBox txt = (TextBox)sender;

            ApplyTextSize(txt.Text);
            this.richTextBoxText.Focus();
        }

        private void ApplyTextSize(string textSize)
        {
            float newSize = Convert.ToSingle(textSize);
            FontFamily currentFontFamily;
            Font newFont;

            currentFontFamily = this.richTextBoxText.SelectionFont.FontFamily;
            newFont = new Font(currentFontFamily, newSize);

            this.richTextBoxText.SelectionFont = newFont;
        }

        private void richTextBoxText_LinkClicked(object sender, LinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start(e.LinkText);
        }

        private void buttonLoad_Click(object sender, EventArgs e)
        {
            try
            {
                OpenFileDialog op = new OpenFileDialog();
                if (op.ShowDialog() == DialogResult.OK)
                {
                    this.textBoxLoad.Text = op.FileName;
                }

                richTextBoxText.LoadFile(this.textBoxLoad.Text);
            }
            catch (System.IO.FileLoadException)
            {
                MessageBox.Show("No file to load yet: " + this.textBoxLoad.Text);
            }
            MessageBox.Show("Load " + this.textBoxLoad.Text);

            this.richTextBoxText.Focus();
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            try
            {
                SaveFileDialog sf = new SaveFileDialog();
                if (sf.ShowDialog() != DialogResult.Cancel)
                {
                    this.textBoxSave.Text = sf.FileName;
                }

                richTextBoxText.SaveFile(this.textBoxSave.Text);
            }
            catch (System.Exception err)
            {
                MessageBox.Show(err.Message);
            }
            MessageBox.Show("Saved " + this.textBoxSave.Text);

            this.richTextBoxText.Focus();
        }

        private SaveFileDialog SaveFileDialog()
        {
            throw new NotImplementedException();
        }

        private void pictureBoxLogo_Click(object sender, EventArgs e)
        {

        }
    }
}
