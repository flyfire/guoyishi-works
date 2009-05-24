namespace ListBoxTest
{
    partial class ListBoxText
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.listBoxSelected = new System.Windows.Forms.ListBox();
            this.checkedListBoxPossibleValue = new System.Windows.Forms.CheckedListBox();
            this.buttonMove = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // listBoxSelected
            // 
            this.listBoxSelected.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.listBoxSelected.FormattingEnabled = true;
            this.listBoxSelected.Location = new System.Drawing.Point(276, 14);
            this.listBoxSelected.Name = "listBoxSelected";
            this.listBoxSelected.SelectionMode = System.Windows.Forms.SelectionMode.MultiExtended;
            this.listBoxSelected.Size = new System.Drawing.Size(182, 238);
            this.listBoxSelected.TabIndex = 0;
            // 
            // checkedListBoxPossibleValue
            // 
            this.checkedListBoxPossibleValue.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)));
            this.checkedListBoxPossibleValue.CheckOnClick = true;
            this.checkedListBoxPossibleValue.FormattingEnabled = true;
            this.checkedListBoxPossibleValue.Items.AddRange(new object[] {
            "alpha",
            "beta",
            "gamma",
            "delta",
            "epsilon",
            "zeta",
            "eta",
            "thet",
            "iot",
            "kappa",
            "lambda",
            "mu",
            "nu",
            "xi",
            "omicron",
            "pi",
            "rho",
            "sigma",
            "tau",
            "upsilon",
            "phi",
            "chi",
            "psi",
            "omega"});
            this.checkedListBoxPossibleValue.Location = new System.Drawing.Point(12, 14);
            this.checkedListBoxPossibleValue.Name = "checkedListBoxPossibleValue";
            this.checkedListBoxPossibleValue.Size = new System.Drawing.Size(179, 244);
            this.checkedListBoxPossibleValue.TabIndex = 1;
            // 
            // buttonMove
            // 
            this.buttonMove.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.buttonMove.Location = new System.Drawing.Point(196, 132);
            this.buttonMove.MaximumSize = new System.Drawing.Size(100, 23);
            this.buttonMove.Name = "buttonMove";
            this.buttonMove.Size = new System.Drawing.Size(75, 23);
            this.buttonMove.TabIndex = 2;
            this.buttonMove.Text = "Move";
            this.buttonMove.UseVisualStyleBackColor = true;
            this.buttonMove.Click += new System.EventHandler(this.buttonMove_Click);
            // 
            // ListBoxText
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(470, 284);
            this.Controls.Add(this.buttonMove);
            this.Controls.Add(this.checkedListBoxPossibleValue);
            this.Controls.Add(this.listBoxSelected);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.MaximizeBox = false;
            this.MinimumSize = new System.Drawing.Size(480, 318);
            this.Name = "ListBoxText";
            this.Text = "ListBoxText 20090516 by Yishi Guo";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListBox listBoxSelected;
        private System.Windows.Forms.CheckedListBox checkedListBoxPossibleValue;
        private System.Windows.Forms.Button buttonMove;
    }
}

