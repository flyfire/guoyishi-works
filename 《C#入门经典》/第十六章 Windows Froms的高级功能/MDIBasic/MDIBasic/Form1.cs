using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace MDIBasic
{
    public partial class FormEditor : Form
    {
        public FormEditor()
        {
            InitializeComponent();

            MDIBasic.FormChild child = new MDIBasic.FormChild(this);

            child.Show();
        }
    }
}
