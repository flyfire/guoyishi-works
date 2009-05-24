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
    public partial class FormChild : Form
    {
        public FormChild(MDIBasic.FormEditor parent)
        {
            InitializeComponent();

            this.MdiParent = parent;
        }
    }
}
