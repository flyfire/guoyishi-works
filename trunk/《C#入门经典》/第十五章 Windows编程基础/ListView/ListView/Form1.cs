using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace ListView
{
    public partial class Form1 : Form
    {
        private System.Collections.Specialized.StringCollection folderCol;

        public Form1()
        {
            InitializeComponent();

            folderCol = new System.Collections.Specialized.StringCollection();
            CreateHeaderAndFillListView();
            PaintListView("");
            folderCol.Add("");
        }

        private void CreateHeaderAndFillListView()
        {
            ColumnHeader colHead;

            colHead = new ColumnHeader();
            colHead.Text = "Filename";
            this.listViewFilesAndFolders.Columns.Add(colHead);

            colHead = new ColumnHeader();
            colHead.Text = "Size";
            this.listViewFilesAndFolders.Columns.Add(colHead);

            colHead = new ColumnHeader();
            colHead.Text = "Last accessed";
            this.listViewFilesAndFolders.Columns.Add(colHead);

            this.listViewFilesAndFolders.Columns[0].Width = 100;
            this.listViewFilesAndFolders.Columns[2].Width = 100;
        }

        private void PaintListView(string root)
        {
            try
            {
                ListViewItem lvi;
                ListViewItem.ListViewSubItem lvsi;

                if (root.CompareTo("") == 0)
                    return;

                DirectoryInfo dir = new DirectoryInfo(root);

                DirectoryInfo[] dirs = dir.GetDirectories();
                FileInfo[] files = dir.GetFiles();

                this.listViewFilesAndFolders.Items.Clear();

                this.listViewFilesAndFolders.BeginUpdate();

                foreach (DirectoryInfo di in dirs)
                {
                    lvi = new ListViewItem();
                    lvi.Text = di.Name;
                    lvi.ImageIndex = 0;
                    lvi.Tag = di.FullName;

                    lvsi = new ListViewItem.ListViewSubItem();
                    lvsi.Text = "-";
                    lvi.SubItems.Add(lvsi);

                    lvsi = new ListViewItem.ListViewSubItem();
                    lvsi.Text = di.LastAccessTime.ToString();
                    lvi.SubItems.Add(lvsi);

                    this.listViewFilesAndFolders.Items.Add(lvi);
                }

                foreach (FileInfo fi in files)
                {
                    lvi = new ListViewItem();
                    lvi.Text = fi.Name;
                    lvi.ImageIndex = 1;
                    lvi.Tag = fi.FullName;

                    lvsi = new ListViewItem.ListViewSubItem();
                    lvsi.Text = fi.Length..ToString();
                    lvi.SubItems.Add(lvsi);

                    lvsi = new ListViewItem.ListViewSubItem();
                    lvsi.Text = fi.LastAccessTime.ToString();
                    lvi.SubItems.Add(lvsi);

                    this.listViewFilesAndFolders.Items.Add(lvi);
                }

                this.listViewFilesAndFolders.EndUpdate();
            }
            catch (System.Exception err)
            {
                MessageBox.Show("Error: " + err.Message);
            }
        }

        private void textBoxOpen_DoubleClick(object sender, EventArgs e)
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();
            if (fbd.ShowDialog() == DialogResult.OK)
            {
                string currentPath = fbd.SelectedPath;
                changeView(currentPath);

                folderCol.Add(currentPath);
            }
        }

        private void buttonBack_Click(object sender, EventArgs e)
        {
            if (folderCol.Count > 1)
            {
                string prevPath = folderCol[folderCol.Count - 2].ToString();
                changeView(prevPath);

                folderCol.RemoveAt(folderCol.Count - 1);
            }
            else
            {
                changeView(this.textBoxOpen.Text);
            }
        }

        private void buttonOpen_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();
            if (fbd.ShowDialog() == DialogResult.OK)
            {
                string currentPath = fbd.SelectedPath;

                changeView(currentPath);

                folderCol.Add(currentPath);
            }
        }

        private void changeView(string Path)
        {
            this.textBoxOpen.Text = Path;
            this.PaintListView(Path);
        }

        private void listViewFilesAndFolders_ItemActivate(object sender, EventArgs e)
        {
            System.Windows.Forms.ListView lw = (System.Windows.Forms.ListView)sender;
            string filename = lw.SelectedItems[0].Tag.ToString();

            if (lw.SelectedItems[0].ImageIndex != 0)
            {
                try
                {
                    System.Diagnostics.Process.Start(filename);
                }
                catch
                {
                    return;
                }
            }
            else
            {
                changeView(filename);
                folderCol.Add(filename);
            }
        }

        private void radioButtonLargeIcon_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rdb = (RadioButton)sender;
            if(rdb.Checked)
                this.listViewFilesAndFolders.View = View.LargeIcon;
        }

        private void textBoxOpen_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == 13)
            {
                string currentPath = this.textBoxOpen.Text;
                changeView(currentPath);

                folderCol.Add(currentPath);
            }
        }

        private void radioButtonSmallIcon_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rdb = (RadioButton)sender;
            if (rdb.Checked)
                this.listViewFilesAndFolders.View = View.SmallIcon;
        }

        private void radioButtonList_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rdb = (RadioButton)sender;
            if (rdb.Checked)
                this.listViewFilesAndFolders.View = View.List;
        }

        private void radioButtonDetails_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rdb = (RadioButton)sender;
            if (rdb.Checked)
                this.listViewFilesAndFolders.View = View.Details;
        }

        private void radioButtonTile_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rdb = (RadioButton)sender;
            if (rdb.Checked)
                this.listViewFilesAndFolders.View = View.Tile;
        }
    }
}
