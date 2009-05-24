using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace LabelTextBox
{
    public partial class ctlLabelTextBox : UserControl
    {
        public enum PositionEnum
        {
            Right,
            Below
        }

        private PositionEnum mPosition = PositionEnum.Right;
        private int mTextboxMargin = 0;
        private string mLabelText = "";

        public PositionEnum Position
        {
            get
            {
                return mPosition;
            }
            set
            {
                mPosition = value;
                MoveControls();

                if (PositionChenged != null)
                {
                    PositionChenged(this, new EventArgs());
                }
            }
        }

        public int TextboxMargin
        {
            get
            {
                return mTextboxMargin;
            }
            set
            {
                mTextboxMargin = value;
            }
        }

        public event System.EventHandler PositionChenged;

        public ctlLabelTextBox()
        {
            InitializeComponent();
        }

        private void ctlLabelTextBox_Load(object sender, EventArgs e)
        {
            lblTextBox.Text = this.Name;

            this.Height = txtLabelText.Height > lblTextBox.Height ? txtLabelText.Height
                : lblTextBox.Height;

            MoveControls();
        }

        private void ctlLabelTextBox_SizeChanged(object sender, EventArgs e)
        {
            MoveControls();
        }

        private void MoveControls()
        {
            switch (mPosition)
            {
                case PositionEnum.Below:
                    this.txtLabelText.Top = this.lblTextBox.Bottom;
                    this.txtLabelText.Left = this.lblTextBox.Left;

                    this.txtLabelText.Width = this.Width;
                    this.Height = txtLabelText.Height + lblTextBox.Height;

                    break;

                case PositionEnum.Right:
                    txtLabelText.Top = lblTextBox.Top;

                    if (mTextboxMargin == 0)
                    {
                        int width = this.Width - lblTextBox.Width - 3;
                        txtLabelText.Left = lblTextBox.Right + 3;
                        txtLabelText.Width = width;
                    }
                    else
                    {
                        txtLabelText.Left = mTextboxMargin;
                        txtLabelText.Width = this.Width - mTextboxMargin;
                    }
                    this.Height = txtLabelText.Height > lblTextBox.Height ?
                        txtLabelText.Height : lblTextBox.Height;

                    break;
            }
        }

        public string LabelText
        {
            get
            {
                return mLabelText;
            }
            set
            {
                mLabelText = value;
                lblTextBox.Text = mLabelText;
                MoveControls();
            }
        }

        public string TextboxText
        {
            get
            {
                return txtLabelText.Text;
            }
            set
            {
                txtLabelText.Text = value;
            }
        }

        private void ctlLabelTextBox_KeyDown(object sender, KeyEventArgs e)
        {
            OnKeyDown(e);
        }

        private void ctlLabelTextBox_KeyUp(object sender, KeyEventArgs e)
        {
            OnKeyUp(e);
        }

        private void ctlLabelTextBox_KeyPress(object sender, KeyPressEventArgs e)
        {
            OnKeyPress(e);
        }
    }
}
