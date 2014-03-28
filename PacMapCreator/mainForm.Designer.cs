namespace PacMapCreator
{
    partial class mainForm
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
            this.controlPnl = new System.Windows.Forms.Panel();
            this.saveBtn = new System.Windows.Forms.Button();
            this.mapSzLabel = new System.Windows.Forms.Label();
            this.generateBtn = new System.Windows.Forms.Button();
            this.sizesList = new System.Windows.Forms.NumericUpDown();
            this.saveDlg = new System.Windows.Forms.SaveFileDialog();
            this.controlPnl.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.sizesList)).BeginInit();
            this.SuspendLayout();
            // 
            // controlPnl
            // 
            this.controlPnl.Controls.Add(this.saveBtn);
            this.controlPnl.Controls.Add(this.mapSzLabel);
            this.controlPnl.Controls.Add(this.generateBtn);
            this.controlPnl.Controls.Add(this.sizesList);
            this.controlPnl.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.controlPnl.Location = new System.Drawing.Point(0, 330);
            this.controlPnl.Name = "controlPnl";
            this.controlPnl.Size = new System.Drawing.Size(332, 100);
            this.controlPnl.TabIndex = 0;
            // 
            // saveBtn
            // 
            this.saveBtn.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.saveBtn.Location = new System.Drawing.Point(181, 61);
            this.saveBtn.Name = "saveBtn";
            this.saveBtn.Size = new System.Drawing.Size(75, 23);
            this.saveBtn.TabIndex = 15;
            this.saveBtn.Text = "Save";
            this.saveBtn.UseVisualStyleBackColor = true;
            this.saveBtn.Click += new System.EventHandler(this.button1_Click);
            // 
            // mapSzLabel
            // 
            this.mapSzLabel.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.mapSzLabel.AutoSize = true;
            this.mapSzLabel.Location = new System.Drawing.Point(104, 32);
            this.mapSzLabel.Name = "mapSzLabel";
            this.mapSzLabel.Size = new System.Drawing.Size(51, 13);
            this.mapSzLabel.TabIndex = 13;
            this.mapSzLabel.Text = "Map Size";
            // 
            // generateBtn
            // 
            this.generateBtn.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.generateBtn.Location = new System.Drawing.Point(181, 32);
            this.generateBtn.Name = "generateBtn";
            this.generateBtn.Size = new System.Drawing.Size(75, 23);
            this.generateBtn.TabIndex = 14;
            this.generateBtn.Text = "Generate";
            this.generateBtn.UseVisualStyleBackColor = true;
            this.generateBtn.Click += new System.EventHandler(this.generateBtn_Click);
            // 
            // sizesList
            // 
            this.sizesList.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.sizesList.Location = new System.Drawing.Point(106, 48);
            this.sizesList.Maximum = new decimal(new int[] {
            25,
            0,
            0,
            0});
            this.sizesList.Minimum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.sizesList.Name = "sizesList";
            this.sizesList.Size = new System.Drawing.Size(69, 20);
            this.sizesList.TabIndex = 12;
            this.sizesList.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            // 
            // saveDlg
            // 
            this.saveDlg.DefaultExt = "*.map";
            this.saveDlg.Filter = "Pacman Maps|*.map";
            this.saveDlg.FileOk += new System.ComponentModel.CancelEventHandler(this.saveFileDialog1_FileOk);
            // 
            // mainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(332, 430);
            this.Controls.Add(this.controlPnl);
            this.Name = "mainForm";
            this.Text = "PacMap Creator";
            this.controlPnl.ResumeLayout(false);
            this.controlPnl.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.sizesList)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel controlPnl;
        private System.Windows.Forms.Label mapSzLabel;
        private System.Windows.Forms.Button generateBtn;
        private System.Windows.Forms.NumericUpDown sizesList;
        private System.Windows.Forms.Button saveBtn;
        private System.Windows.Forms.SaveFileDialog saveDlg;




    }
}

