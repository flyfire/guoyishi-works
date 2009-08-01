using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace SwitchNet
{
    /// <summary>
    /// Get the name of new profile
    /// </summary>
    public partial class NewProfileDialog : Form
    {
        private FormNetConfig MainForm;

        private string _Text
        {
            get
            {
                string str = null;
                str += textBoxName.Text.TrimEnd(' ');
                str = str.TrimStart(' ');

                return str;
            }
        }

        public NewProfileDialog(FormNetConfig MainForm)
        {
            InitializeComponent();

            this.MainForm = MainForm;
        }

        #region private Methods

        private bool isTextValid()
        {
            if (_Text.Length == 0)
            {
                return false;
            }
            else if (isSpaceString())
            {
                return false;
            }

            return true;
        }

        private bool isSpaceString()
        {
            string text = _Text;

            foreach (char ch in text)
            {
                if (ch != ' ')
                    return false;
            }

            return true;
        }

        private bool isNameExist()
        {
            foreach (Profile profile in MainForm._Profiles)
            {
                if (_Text.Equals(profile.Name))
                    return true;
            }

            return false;
        }

        private bool isClickOK()
        {
            if (!isNameExist() && isTextValid())
                return true;
            else
                return false;
        }

        private void btnOKEnable()
        {
            if (isClickOK())
            {
                buttonOK.Enabled = true;
            }
            else
            {
                buttonOK.Enabled = false;
            }
        }

        #endregion

        #region Events


        private void buttonOK_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.OK;
            this.Hide();
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
            this.Hide();
        }

        private void textBoxName_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == 13)
            {
                textBoxName.Text = _Text;
                if (isTextValid())
                {
                    if (isClickOK())
                        buttonOK_Click(sender, e);
                }
                else
                {
                    MessageBox.Show("Please enter a valid name!", "Invalid Name!", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }

                if (!isNameExist())
                {
                    if (isClickOK())
                        buttonOK_Click(sender, e);
                }
                else
                {
                    MessageBox.Show("The profile name had been existed!", "Invalid Name!", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
        }

        private void textBoxName_TextChanged(object sender, EventArgs e)
        {
            btnOKEnable();
        }

        #endregion

        #region public properties

        public string NewProfileName
        {
            get
            {
                return this._Text;
            }
        }

        #endregion




    }
}
