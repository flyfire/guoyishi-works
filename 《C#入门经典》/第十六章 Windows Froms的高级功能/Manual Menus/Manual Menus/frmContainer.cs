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
    public partial class frmContainer : Form
    {
        private int mCounter;
        public frmContainer()
        {
            InitializeComponent();
            mCounter = 1;

            frmEditor newForm = new frmEditor(this, mCounter);
            newForm.Show();
        }

        private void ToolStripMenuItemNew_Click(object sender, EventArgs e)
        {
            frmEditor newForm = new frmEditor(this, ++mCounter);
            newForm.Show();
        }

        private void ToolStripMenuItemTile_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileHorizontal);
        }

        private void ToolStripMenuItemCascade_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.Cascade);
        }
    }
}
