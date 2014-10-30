namespace CS6
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.Exit = new System.Windows.Forms.Button();
            this.Clear = new System.Windows.Forms.Button();
            this.Calculate = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.totalnettxt = new System.Windows.Forms.TextBox();
            this.label13 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.nettxt = new System.Windows.Forms.TextBox();
            this.uniontxt = new System.Windows.Forms.TextBox();
            this.federaltxt = new System.Windows.Forms.TextBox();
            this.statetxt = new System.Windows.Forms.TextBox();
            this.ficatxt = new System.Windows.Forms.TextBox();
            this.grosstxt = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.GRPdues = new System.Windows.Forms.GroupBox();
            this.RADspec = new System.Windows.Forms.RadioButton();
            this.RADreg = new System.Windows.Forms.RadioButton();
            this.RADnone = new System.Windows.Forms.RadioButton();
            this.rate = new System.Windows.Forms.TextBox();
            this.hours = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.calculateToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.clearFormToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.fontToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.colorToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.counttxt = new System.Windows.Forms.TextBox();
            this.avgnettxt = new System.Windows.Forms.TextBox();
            this.groupBox3.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.GRPdues.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            this.SuspendLayout();
            // 
            // Exit
            // 
            this.Exit.Location = new System.Drawing.Point(222, 607);
            this.Exit.Name = "Exit";
            this.Exit.Size = new System.Drawing.Size(96, 22);
            this.Exit.TabIndex = 35;
            this.Exit.Text = "E&xit";
            this.Exit.UseVisualStyleBackColor = true;
            this.Exit.Click += new System.EventHandler(this.Exit_Click);
            // 
            // Clear
            // 
            this.Clear.Location = new System.Drawing.Point(118, 607);
            this.Clear.Name = "Clear";
            this.Clear.Size = new System.Drawing.Size(96, 22);
            this.Clear.TabIndex = 34;
            this.Clear.Text = "C&lear Form";
            this.Clear.UseVisualStyleBackColor = true;
            this.Clear.Click += new System.EventHandler(this.Clear_Click);
            // 
            // Calculate
            // 
            this.Calculate.Location = new System.Drawing.Point(14, 607);
            this.Calculate.Name = "Calculate";
            this.Calculate.Size = new System.Drawing.Size(96, 22);
            this.Calculate.TabIndex = 33;
            this.Calculate.Text = "&Calculate";
            this.Calculate.UseVisualStyleBackColor = true;
            this.Calculate.Click += new System.EventHandler(this.Calculate_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.avgnettxt);
            this.groupBox3.Controls.Add(this.counttxt);
            this.groupBox3.Controls.Add(this.totalnettxt);
            this.groupBox3.Controls.Add(this.label13);
            this.groupBox3.Controls.Add(this.label12);
            this.groupBox3.Controls.Add(this.label11);
            this.groupBox3.Location = new System.Drawing.Point(21, 492);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(292, 109);
            this.groupBox3.TabIndex = 32;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Totals";
            // 
            // totalnettxt
            // 
            this.totalnettxt.BackColor = System.Drawing.SystemColors.Control;
            this.totalnettxt.ForeColor = System.Drawing.Color.Black;
            this.totalnettxt.Location = new System.Drawing.Point(116, 20);
            this.totalnettxt.Name = "totalnettxt";
            this.totalnettxt.ReadOnly = true;
            this.totalnettxt.Size = new System.Drawing.Size(143, 20);
            this.totalnettxt.TabIndex = 22;
            this.totalnettxt.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(21, 81);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(85, 13);
            this.label13.TabIndex = 21;
            this.label13.Text = "Avrage Net Pay:";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(19, 52);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(87, 13);
            this.label12.TabIndex = 20;
            this.label12.Text = "Employee Count:";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(31, 23);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(75, 13);
            this.label11.TabIndex = 19;
            this.label11.Text = "Total Net Pay:";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.nettxt);
            this.groupBox2.Controls.Add(this.uniontxt);
            this.groupBox2.Controls.Add(this.federaltxt);
            this.groupBox2.Controls.Add(this.statetxt);
            this.groupBox2.Controls.Add(this.ficatxt);
            this.groupBox2.Controls.Add(this.grosstxt);
            this.groupBox2.Controls.Add(this.label8);
            this.groupBox2.Controls.Add(this.label9);
            this.groupBox2.Controls.Add(this.label10);
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Controls.Add(this.label6);
            this.groupBox2.Controls.Add(this.label5);
            this.groupBox2.Location = new System.Drawing.Point(19, 205);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(295, 299);
            this.groupBox2.TabIndex = 31;
            this.groupBox2.TabStop = false;
            // 
            // nettxt
            // 
            this.nettxt.Location = new System.Drawing.Point(118, 263);
            this.nettxt.Name = "nettxt";
            this.nettxt.ReadOnly = true;
            this.nettxt.Size = new System.Drawing.Size(144, 20);
            this.nettxt.TabIndex = 17;
            this.nettxt.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // uniontxt
            // 
            this.uniontxt.Location = new System.Drawing.Point(118, 214);
            this.uniontxt.Name = "uniontxt";
            this.uniontxt.ReadOnly = true;
            this.uniontxt.Size = new System.Drawing.Size(144, 20);
            this.uniontxt.TabIndex = 16;
            this.uniontxt.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // federaltxt
            // 
            this.federaltxt.Location = new System.Drawing.Point(118, 165);
            this.federaltxt.Name = "federaltxt";
            this.federaltxt.ReadOnly = true;
            this.federaltxt.Size = new System.Drawing.Size(144, 20);
            this.federaltxt.TabIndex = 15;
            this.federaltxt.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // statetxt
            // 
            this.statetxt.Location = new System.Drawing.Point(118, 116);
            this.statetxt.Name = "statetxt";
            this.statetxt.ReadOnly = true;
            this.statetxt.Size = new System.Drawing.Size(144, 20);
            this.statetxt.TabIndex = 14;
            this.statetxt.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // ficatxt
            // 
            this.ficatxt.Location = new System.Drawing.Point(118, 67);
            this.ficatxt.Name = "ficatxt";
            this.ficatxt.ReadOnly = true;
            this.ficatxt.Size = new System.Drawing.Size(144, 20);
            this.ficatxt.TabIndex = 13;
            this.ficatxt.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // grosstxt
            // 
            this.grosstxt.Location = new System.Drawing.Point(118, 18);
            this.grosstxt.Name = "grosstxt";
            this.grosstxt.ReadOnly = true;
            this.grosstxt.Size = new System.Drawing.Size(144, 20);
            this.grosstxt.TabIndex = 12;
            this.grosstxt.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(60, 267);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(48, 13);
            this.label8.TabIndex = 11;
            this.label8.Text = "Net Pay:";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(42, 218);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(66, 13);
            this.label9.TabIndex = 10;
            this.label9.Text = "Union Dues:";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(42, 168);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(66, 13);
            this.label10.TabIndex = 9;
            this.label10.Text = "Federal Tax:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(52, 119);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(56, 13);
            this.label7.TabIndex = 8;
            this.label7.Text = "State Tax:";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(54, 70);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(54, 13);
            this.label6.TabIndex = 7;
            this.label6.Text = "FICA Tax:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(50, 21);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(58, 13);
            this.label5.TabIndex = 6;
            this.label5.Text = "Gross Pay:";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.GRPdues);
            this.groupBox1.Controls.Add(this.rate);
            this.groupBox1.Controls.Add(this.hours);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Location = new System.Drawing.Point(19, 65);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(295, 122);
            this.groupBox1.TabIndex = 30;
            this.groupBox1.TabStop = false;
            // 
            // GRPdues
            // 
            this.GRPdues.Controls.Add(this.RADspec);
            this.GRPdues.Controls.Add(this.RADreg);
            this.GRPdues.Controls.Add(this.RADnone);
            this.GRPdues.ForeColor = System.Drawing.SystemColors.ControlText;
            this.GRPdues.Location = new System.Drawing.Point(32, 66);
            this.GRPdues.Name = "GRPdues";
            this.GRPdues.Size = new System.Drawing.Size(230, 51);
            this.GRPdues.TabIndex = 8;
            this.GRPdues.TabStop = false;
            this.GRPdues.Text = "Union Dues";
            // 
            // RADspec
            // 
            this.RADspec.AutoSize = true;
            this.RADspec.Location = new System.Drawing.Point(151, 20);
            this.RADspec.Name = "RADspec";
            this.RADspec.Size = new System.Drawing.Size(60, 17);
            this.RADspec.TabIndex = 7;
            this.RADspec.TabStop = true;
            this.RADspec.Text = "Special";
            this.RADspec.UseVisualStyleBackColor = true;
            // 
            // RADreg
            // 
            this.RADreg.AutoSize = true;
            this.RADreg.Location = new System.Drawing.Point(83, 20);
            this.RADreg.Name = "RADreg";
            this.RADreg.Size = new System.Drawing.Size(62, 17);
            this.RADreg.TabIndex = 6;
            this.RADreg.TabStop = true;
            this.RADreg.Text = "Regular";
            this.RADreg.UseVisualStyleBackColor = true;
            // 
            // RADnone
            // 
            this.RADnone.AutoSize = true;
            this.RADnone.Checked = true;
            this.RADnone.Location = new System.Drawing.Point(26, 20);
            this.RADnone.Name = "RADnone";
            this.RADnone.Size = new System.Drawing.Size(51, 17);
            this.RADnone.TabIndex = 5;
            this.RADnone.TabStop = true;
            this.RADnone.Text = "None";
            this.RADnone.UseVisualStyleBackColor = true;
            // 
            // rate
            // 
            this.rate.Location = new System.Drawing.Point(118, 40);
            this.rate.Name = "rate";
            this.rate.Size = new System.Drawing.Size(144, 20);
            this.rate.TabIndex = 4;
            this.rate.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // hours
            // 
            this.hours.Location = new System.Drawing.Point(118, 15);
            this.hours.Name = "hours";
            this.hours.Size = new System.Drawing.Size(144, 20);
            this.hours.TabIndex = 3;
            this.hours.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(54, 43);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(54, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Pay Rate:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(29, 18);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(79, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Hours Worked:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Underline))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(83, 34);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(166, 25);
            this.label1.TabIndex = 29;
            this.label1.Text = "Pay Calculator";
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.editToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(332, 24);
            this.menuStrip1.TabIndex = 36;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.exitToolStripMenuItem.Text = "E&xit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // editToolStripMenuItem
            // 
            this.editToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.calculateToolStripMenuItem,
            this.clearFormToolStripMenuItem,
            this.toolStripSeparator1,
            this.fontToolStripMenuItem,
            this.colorToolStripMenuItem});
            this.editToolStripMenuItem.Name = "editToolStripMenuItem";
            this.editToolStripMenuItem.Size = new System.Drawing.Size(39, 20);
            this.editToolStripMenuItem.Text = "&Edit";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(51, 34);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(31, 25);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 37;
            this.pictureBox1.TabStop = false;
            // 
            // pictureBox2
            // 
            this.pictureBox2.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox2.Image")));
            this.pictureBox2.Location = new System.Drawing.Point(249, 34);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(31, 25);
            this.pictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox2.TabIndex = 38;
            this.pictureBox2.TabStop = false;
            // 
            // calculateToolStripMenuItem
            // 
            this.calculateToolStripMenuItem.Name = "calculateToolStripMenuItem";
            this.calculateToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.calculateToolStripMenuItem.Text = "Calculate";
            this.calculateToolStripMenuItem.Click += new System.EventHandler(this.calculateToolStripMenuItem_Click);
            // 
            // clearFormToolStripMenuItem
            // 
            this.clearFormToolStripMenuItem.Name = "clearFormToolStripMenuItem";
            this.clearFormToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.clearFormToolStripMenuItem.Text = "Clear Form";
            this.clearFormToolStripMenuItem.Click += new System.EventHandler(this.clearFormToolStripMenuItem_Click);
            // 
            // fontToolStripMenuItem
            // 
            this.fontToolStripMenuItem.Name = "fontToolStripMenuItem";
            this.fontToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.fontToolStripMenuItem.Text = "Font";
            this.fontToolStripMenuItem.Click += new System.EventHandler(this.fontToolStripMenuItem_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(149, 6);
            // 
            // colorToolStripMenuItem
            // 
            this.colorToolStripMenuItem.Name = "colorToolStripMenuItem";
            this.colorToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.colorToolStripMenuItem.Text = "Color ";
            this.colorToolStripMenuItem.Click += new System.EventHandler(this.colorToolStripMenuItem_Click);
            // 
            // colorDialog1
            // 
            this.colorDialog1.AnyColor = true;
            this.colorDialog1.Color = System.Drawing.Color.MidnightBlue;
            this.colorDialog1.FullOpen = true;
            // 
            // counttxt
            // 
            this.counttxt.BackColor = System.Drawing.SystemColors.Control;
            this.counttxt.ForeColor = System.Drawing.Color.Black;
            this.counttxt.Location = new System.Drawing.Point(117, 52);
            this.counttxt.Name = "counttxt";
            this.counttxt.ReadOnly = true;
            this.counttxt.Size = new System.Drawing.Size(143, 20);
            this.counttxt.TabIndex = 23;
            this.counttxt.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // avgnettxt
            // 
            this.avgnettxt.BackColor = System.Drawing.SystemColors.Control;
            this.avgnettxt.ForeColor = System.Drawing.Color.Black;
            this.avgnettxt.Location = new System.Drawing.Point(117, 78);
            this.avgnettxt.Name = "avgnettxt";
            this.avgnettxt.ReadOnly = true;
            this.avgnettxt.Size = new System.Drawing.Size(143, 20);
            this.avgnettxt.TabIndex = 24;
            this.avgnettxt.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(332, 668);
            this.Controls.Add(this.pictureBox2);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.Exit);
            this.Controls.Add(this.Clear);
            this.Controls.Add(this.Calculate);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "CS6 By Jared Adamson";
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.GRPdues.ResumeLayout(false);
            this.GRPdues.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Exit;
        private System.Windows.Forms.Button Clear;
        private System.Windows.Forms.Button Calculate;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox nettxt;
        private System.Windows.Forms.TextBox uniontxt;
        private System.Windows.Forms.TextBox federaltxt;
        private System.Windows.Forms.TextBox statetxt;
        private System.Windows.Forms.TextBox ficatxt;
        private System.Windows.Forms.TextBox grosstxt;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox rate;
        private System.Windows.Forms.TextBox hours;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox GRPdues;
        private System.Windows.Forms.RadioButton RADspec;
        private System.Windows.Forms.RadioButton RADreg;
        private System.Windows.Forms.RadioButton RADnone;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.ToolStripMenuItem calculateToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem clearFormToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem fontToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem colorToolStripMenuItem;
        private System.Windows.Forms.ColorDialog colorDialog1;
        public System.Windows.Forms.TextBox totalnettxt;
        public System.Windows.Forms.TextBox avgnettxt;
        public System.Windows.Forms.TextBox counttxt;
    }
}

