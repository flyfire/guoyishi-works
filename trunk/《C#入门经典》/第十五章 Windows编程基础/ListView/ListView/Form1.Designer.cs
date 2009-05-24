namespace ListView
{
    partial class Form1
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.listViewFilesAndFolders = new System.Windows.Forms.ListView();
            this.imageListLarge = new System.Windows.Forms.ImageList(this.components);
            this.imageListSmall = new System.Windows.Forms.ImageList(this.components);
            this.groupBoxViewMode = new System.Windows.Forms.GroupBox();
            this.radioButtonTile = new System.Windows.Forms.RadioButton();
            this.radioButtonDetails = new System.Windows.Forms.RadioButton();
            this.radioButtonList = new System.Windows.Forms.RadioButton();
            this.radioButtonSmallIcon = new System.Windows.Forms.RadioButton();
            this.radioButtonLargeIcon = new System.Windows.Forms.RadioButton();
            this.buttonBack = new System.Windows.Forms.Button();
            this.buttonOpen = new System.Windows.Forms.Button();
            this.textBoxOpen = new System.Windows.Forms.TextBox();
            this.groupBoxViewMode.SuspendLayout();
            this.SuspendLayout();
            // 
            // listViewFilesAndFolders
            // 
            this.listViewFilesAndFolders.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.listViewFilesAndFolders.LargeImageList = this.imageListLarge;
            this.listViewFilesAndFolders.Location = new System.Drawing.Point(15, 33);
            this.listViewFilesAndFolders.Name = "listViewFilesAndFolders";
            this.listViewFilesAndFolders.Size = new System.Drawing.Size(345, 260);
            this.listViewFilesAndFolders.SmallImageList = this.imageListSmall;
            this.listViewFilesAndFolders.TabIndex = 1;
            this.listViewFilesAndFolders.UseCompatibleStateImageBehavior = false;
            this.listViewFilesAndFolders.View = System.Windows.Forms.View.Details;
            this.listViewFilesAndFolders.ItemActivate += new System.EventHandler(this.listViewFilesAndFolders_ItemActivate);
            // 
            // imageListLarge
            // 
            this.imageListLarge.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageListLarge.ImageStream")));
            this.imageListLarge.TransparentColor = System.Drawing.Color.Transparent;
            this.imageListLarge.Images.SetKeyName(0, "Folder32x32.ICO");
            this.imageListLarge.Images.SetKeyName(1, "Text 32x32.ICO");
            // 
            // imageListSmall
            // 
            this.imageListSmall.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageListSmall.ImageStream")));
            this.imageListSmall.TransparentColor = System.Drawing.Color.Transparent;
            this.imageListSmall.Images.SetKeyName(0, "Folder 16x16.ICO");
            this.imageListSmall.Images.SetKeyName(1, "Text 16x16.ICO");
            // 
            // groupBoxViewMode
            // 
            this.groupBoxViewMode.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBoxViewMode.Controls.Add(this.radioButtonTile);
            this.groupBoxViewMode.Controls.Add(this.radioButtonDetails);
            this.groupBoxViewMode.Controls.Add(this.radioButtonList);
            this.groupBoxViewMode.Controls.Add(this.radioButtonSmallIcon);
            this.groupBoxViewMode.Controls.Add(this.radioButtonLargeIcon);
            this.groupBoxViewMode.Location = new System.Drawing.Point(367, 25);
            this.groupBoxViewMode.Name = "groupBoxViewMode";
            this.groupBoxViewMode.Size = new System.Drawing.Size(152, 239);
            this.groupBoxViewMode.TabIndex = 2;
            this.groupBoxViewMode.TabStop = false;
            this.groupBoxViewMode.Text = "View Mode";
            // 
            // radioButtonTile
            // 
            this.radioButtonTile.AutoSize = true;
            this.radioButtonTile.Location = new System.Drawing.Point(6, 111);
            this.radioButtonTile.Name = "radioButtonTile";
            this.radioButtonTile.Size = new System.Drawing.Size(42, 17);
            this.radioButtonTile.TabIndex = 4;
            this.radioButtonTile.TabStop = true;
            this.radioButtonTile.Text = "Tile";
            this.radioButtonTile.UseVisualStyleBackColor = true;
            this.radioButtonTile.CheckedChanged += new System.EventHandler(this.radioButtonTile_CheckedChanged);
            // 
            // radioButtonDetails
            // 
            this.radioButtonDetails.AutoSize = true;
            this.radioButtonDetails.Checked = true;
            this.radioButtonDetails.Location = new System.Drawing.Point(6, 88);
            this.radioButtonDetails.Name = "radioButtonDetails";
            this.radioButtonDetails.Size = new System.Drawing.Size(57, 17);
            this.radioButtonDetails.TabIndex = 3;
            this.radioButtonDetails.TabStop = true;
            this.radioButtonDetails.Text = "Details";
            this.radioButtonDetails.UseVisualStyleBackColor = true;
            this.radioButtonDetails.CheckedChanged += new System.EventHandler(this.radioButtonDetails_CheckedChanged);
            // 
            // radioButtonList
            // 
            this.radioButtonList.AutoSize = true;
            this.radioButtonList.Location = new System.Drawing.Point(6, 65);
            this.radioButtonList.Name = "radioButtonList";
            this.radioButtonList.Size = new System.Drawing.Size(41, 17);
            this.radioButtonList.TabIndex = 2;
            this.radioButtonList.TabStop = true;
            this.radioButtonList.Text = "List";
            this.radioButtonList.UseVisualStyleBackColor = true;
            this.radioButtonList.CheckedChanged += new System.EventHandler(this.radioButtonList_CheckedChanged);
            // 
            // radioButtonSmallIcon
            // 
            this.radioButtonSmallIcon.AutoSize = true;
            this.radioButtonSmallIcon.Location = new System.Drawing.Point(6, 42);
            this.radioButtonSmallIcon.Name = "radioButtonSmallIcon";
            this.radioButtonSmallIcon.Size = new System.Drawing.Size(71, 17);
            this.radioButtonSmallIcon.TabIndex = 1;
            this.radioButtonSmallIcon.TabStop = true;
            this.radioButtonSmallIcon.Text = "SmallIcon";
            this.radioButtonSmallIcon.UseVisualStyleBackColor = true;
            this.radioButtonSmallIcon.CheckedChanged += new System.EventHandler(this.radioButtonSmallIcon_CheckedChanged);
            // 
            // radioButtonLargeIcon
            // 
            this.radioButtonLargeIcon.AutoSize = true;
            this.radioButtonLargeIcon.Location = new System.Drawing.Point(6, 19);
            this.radioButtonLargeIcon.Name = "radioButtonLargeIcon";
            this.radioButtonLargeIcon.Size = new System.Drawing.Size(73, 17);
            this.radioButtonLargeIcon.TabIndex = 0;
            this.radioButtonLargeIcon.TabStop = true;
            this.radioButtonLargeIcon.Text = "LargeIcon";
            this.radioButtonLargeIcon.UseVisualStyleBackColor = true;
            this.radioButtonLargeIcon.CheckedChanged += new System.EventHandler(this.radioButtonLargeIcon_CheckedChanged);
            // 
            // buttonBack
            // 
            this.buttonBack.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonBack.Location = new System.Drawing.Point(366, 270);
            this.buttonBack.Name = "buttonBack";
            this.buttonBack.Size = new System.Drawing.Size(75, 23);
            this.buttonBack.TabIndex = 3;
            this.buttonBack.Text = "Backward";
            this.buttonBack.UseVisualStyleBackColor = true;
            this.buttonBack.Click += new System.EventHandler(this.buttonBack_Click);
            // 
            // buttonOpen
            // 
            this.buttonOpen.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonOpen.Location = new System.Drawing.Point(285, 7);
            this.buttonOpen.Name = "buttonOpen";
            this.buttonOpen.Size = new System.Drawing.Size(75, 22);
            this.buttonOpen.TabIndex = 4;
            this.buttonOpen.Text = "Open";
            this.buttonOpen.UseVisualStyleBackColor = true;
            this.buttonOpen.Click += new System.EventHandler(this.buttonOpen_Click);
            // 
            // textBoxOpen
            // 
            this.textBoxOpen.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.textBoxOpen.Location = new System.Drawing.Point(15, 7);
            this.textBoxOpen.Name = "textBoxOpen";
            this.textBoxOpen.Size = new System.Drawing.Size(264, 20);
            this.textBoxOpen.TabIndex = 5;
            this.textBoxOpen.DoubleClick += new System.EventHandler(this.textBoxOpen_DoubleClick);
            this.textBoxOpen.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBoxOpen_KeyPress);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(525, 309);
            this.Controls.Add(this.textBoxOpen);
            this.Controls.Add(this.buttonOpen);
            this.Controls.Add(this.buttonBack);
            this.Controls.Add(this.groupBoxViewMode);
            this.Controls.Add(this.listViewFilesAndFolders);
            this.MinimumSize = new System.Drawing.Size(533, 341);
            this.Name = "Form1";
            this.Text = "ListView";
            this.groupBoxViewMode.ResumeLayout(false);
            this.groupBoxViewMode.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListView listViewFilesAndFolders;
        private System.Windows.Forms.GroupBox groupBoxViewMode;
        private System.Windows.Forms.RadioButton radioButtonTile;
        private System.Windows.Forms.RadioButton radioButtonDetails;
        private System.Windows.Forms.RadioButton radioButtonList;
        private System.Windows.Forms.RadioButton radioButtonSmallIcon;
        private System.Windows.Forms.RadioButton radioButtonLargeIcon;
        private System.Windows.Forms.Button buttonBack;
        private System.Windows.Forms.ImageList imageListSmall;
        private System.Windows.Forms.ImageList imageListLarge;
        private System.Windows.Forms.Button buttonOpen;
        private System.Windows.Forms.TextBox textBoxOpen;
    }
}

