namespace LabelTextBoxTest
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
            this.ctlLabelTextBox1 = new LabelTextBox.ctlLabelTextBox();
            this.SuspendLayout();
            // 
            // ctlLabelTextBox1
            // 
            this.ctlLabelTextBox1.LabelText = "";
            this.ctlLabelTextBox1.Location = new System.Drawing.Point(82, 100);
            this.ctlLabelTextBox1.Name = "ctlLabelTextBox1";
            this.ctlLabelTextBox1.Position = LabelTextBox.ctlLabelTextBox.PositionEnum.Right;
            this.ctlLabelTextBox1.Size = new System.Drawing.Size(156, 20);
            this.ctlLabelTextBox1.TabIndex = 0;
            this.ctlLabelTextBox1.TextboxMargin = 0;
            this.ctlLabelTextBox1.TextboxText = "";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(292, 268);
            this.Controls.Add(this.ctlLabelTextBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private LabelTextBox.ctlLabelTextBox ctlLabelTextBox1;

    }
}

