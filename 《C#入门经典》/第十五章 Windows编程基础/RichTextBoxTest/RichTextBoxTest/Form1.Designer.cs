namespace RichTextBoxTest
{
    partial class RichTextBoxTest
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
            this.buttonBold = new System.Windows.Forms.Button();
            this.buttonUnderline = new System.Windows.Forms.Button();
            this.buttonItalic = new System.Windows.Forms.Button();
            this.buttonCenter = new System.Windows.Forms.Button();
            this.labelSize = new System.Windows.Forms.Label();
            this.textBoxSize = new System.Windows.Forms.TextBox();
            this.richTextBoxText = new System.Windows.Forms.RichTextBox();
            this.buttonLoad = new System.Windows.Forms.Button();
            this.buttonSave = new System.Windows.Forms.Button();
            this.textBoxLoad = new System.Windows.Forms.TextBox();
            this.textBoxSave = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // buttonBold
            // 
            this.buttonBold.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.buttonBold.Location = new System.Drawing.Point(104, 12);
            this.buttonBold.Name = "buttonBold";
            this.buttonBold.Size = new System.Drawing.Size(75, 23);
            this.buttonBold.TabIndex = 0;
            this.buttonBold.Text = "Bold";
            this.buttonBold.UseVisualStyleBackColor = true;
            this.buttonBold.Click += new System.EventHandler(this.buttonBold_Click);
            // 
            // buttonUnderline
            // 
            this.buttonUnderline.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.buttonUnderline.Location = new System.Drawing.Point(224, 12);
            this.buttonUnderline.Name = "buttonUnderline";
            this.buttonUnderline.Size = new System.Drawing.Size(75, 23);
            this.buttonUnderline.TabIndex = 1;
            this.buttonUnderline.Text = "Underline";
            this.buttonUnderline.UseVisualStyleBackColor = true;
            this.buttonUnderline.Click += new System.EventHandler(this.buttonUnderline_Click);
            // 
            // buttonItalic
            // 
            this.buttonItalic.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.buttonItalic.Location = new System.Drawing.Point(344, 12);
            this.buttonItalic.Name = "buttonItalic";
            this.buttonItalic.Size = new System.Drawing.Size(75, 23);
            this.buttonItalic.TabIndex = 2;
            this.buttonItalic.Text = "Italic";
            this.buttonItalic.UseVisualStyleBackColor = true;
            this.buttonItalic.Click += new System.EventHandler(this.buttonItalic_Click);
            // 
            // buttonCenter
            // 
            this.buttonCenter.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.buttonCenter.Location = new System.Drawing.Point(464, 12);
            this.buttonCenter.Name = "buttonCenter";
            this.buttonCenter.Size = new System.Drawing.Size(75, 23);
            this.buttonCenter.TabIndex = 3;
            this.buttonCenter.Text = "Center";
            this.buttonCenter.UseVisualStyleBackColor = true;
            this.buttonCenter.Click += new System.EventHandler(this.buttonCenter_Click);
            // 
            // labelSize
            // 
            this.labelSize.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.labelSize.AutoSize = true;
            this.labelSize.Location = new System.Drawing.Point(245, 63);
            this.labelSize.Name = "labelSize";
            this.labelSize.Size = new System.Drawing.Size(27, 13);
            this.labelSize.TabIndex = 4;
            this.labelSize.Text = "Size";
            // 
            // textBoxSize
            // 
            this.textBoxSize.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.textBoxSize.Location = new System.Drawing.Point(305, 56);
            this.textBoxSize.MaxLength = 10;
            this.textBoxSize.Name = "textBoxSize";
            this.textBoxSize.Size = new System.Drawing.Size(100, 20);
            this.textBoxSize.TabIndex = 5;
            this.textBoxSize.Validated += new System.EventHandler(this.textBoxSize_Validated);
            this.textBoxSize.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBoxSize_KeyPress);
            // 
            // richTextBoxText
            // 
            this.richTextBoxText.AcceptsTab = true;
            this.richTextBoxText.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.richTextBoxText.CausesValidation = false;
            this.richTextBoxText.Cursor = System.Windows.Forms.Cursors.IBeam;
            this.richTextBoxText.Location = new System.Drawing.Point(44, 106);
            this.richTextBoxText.Name = "richTextBoxText";
            this.richTextBoxText.Size = new System.Drawing.Size(555, 154);
            this.richTextBoxText.TabIndex = 0;
            this.richTextBoxText.Text = "";
            this.richTextBoxText.LinkClicked += new System.Windows.Forms.LinkClickedEventHandler(this.richTextBoxText_LinkClicked);
            // 
            // buttonLoad
            // 
            this.buttonLoad.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonLoad.Location = new System.Drawing.Point(524, 267);
            this.buttonLoad.Name = "buttonLoad";
            this.buttonLoad.Size = new System.Drawing.Size(75, 22);
            this.buttonLoad.TabIndex = 7;
            this.buttonLoad.Text = "Load";
            this.buttonLoad.UseVisualStyleBackColor = true;
            this.buttonLoad.Click += new System.EventHandler(this.buttonLoad_Click);
            // 
            // buttonSave
            // 
            this.buttonSave.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonSave.Location = new System.Drawing.Point(524, 296);
            this.buttonSave.Name = "buttonSave";
            this.buttonSave.Size = new System.Drawing.Size(75, 22);
            this.buttonSave.TabIndex = 8;
            this.buttonSave.Text = "Save";
            this.buttonSave.UseVisualStyleBackColor = true;
            this.buttonSave.Click += new System.EventHandler(this.buttonSave_Click);
            // 
            // textBoxLoad
            // 
            this.textBoxLoad.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.textBoxLoad.Location = new System.Drawing.Point(44, 267);
            this.textBoxLoad.Name = "textBoxLoad";
            this.textBoxLoad.Size = new System.Drawing.Size(474, 20);
            this.textBoxLoad.TabIndex = 9;
            this.textBoxLoad.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // textBoxSave
            // 
            this.textBoxSave.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.textBoxSave.Location = new System.Drawing.Point(44, 298);
            this.textBoxSave.Name = "textBoxSave";
            this.textBoxSave.Size = new System.Drawing.Size(474, 20);
            this.textBoxSave.TabIndex = 10;
            this.textBoxSave.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // RichTextBoxTest
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(642, 372);
            this.Controls.Add(this.textBoxSave);
            this.Controls.Add(this.textBoxLoad);
            this.Controls.Add(this.buttonSave);
            this.Controls.Add(this.buttonLoad);
            this.Controls.Add(this.richTextBoxText);
            this.Controls.Add(this.textBoxSize);
            this.Controls.Add(this.labelSize);
            this.Controls.Add(this.buttonCenter);
            this.Controls.Add(this.buttonItalic);
            this.Controls.Add(this.buttonUnderline);
            this.Controls.Add(this.buttonBold);
            this.MinimumSize = new System.Drawing.Size(650, 404);
            this.Name = "RichTextBoxTest";
            this.Text = "Rich Text Box Test";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonBold;
        private System.Windows.Forms.Button buttonUnderline;
        private System.Windows.Forms.Button buttonItalic;
        private System.Windows.Forms.Button buttonCenter;
        private System.Windows.Forms.Label labelSize;
        private System.Windows.Forms.TextBox textBoxSize;
        private System.Windows.Forms.RichTextBox richTextBoxText;
        private System.Windows.Forms.Button buttonLoad;
        private System.Windows.Forms.Button buttonSave;
        private System.Windows.Forms.TextBox textBoxLoad;
        private System.Windows.Forms.TextBox textBoxSave;
    }
}

