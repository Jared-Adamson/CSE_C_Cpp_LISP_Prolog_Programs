namespace CS4
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.hours = new System.Windows.Forms.TextBox();
            this.rate = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.grosstxt = new System.Windows.Forms.TextBox();
            this.ficatxt = new System.Windows.Forms.TextBox();
            this.statetxt = new System.Windows.Forms.TextBox();
            this.federaltxt = new System.Windows.Forms.TextBox();
            this.uniontxt = new System.Windows.Forms.TextBox();
            this.nettxt = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.totalnettxt = new System.Windows.Forms.TextBox();
            this.counttxt = new System.Windows.Forms.TextBox();
            this.avgnettxt = new System.Windows.Forms.TextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.Calculate = new System.Windows.Forms.Button();
            this.Clear = new System.Windows.Forms.Button();
            this.Exit = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Underline))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(96, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(166, 25);
            this.label1.TabIndex = 0;
            this.label1.Text = "Pay Calculator";
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
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(54, 43);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(54, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Pay Rate:";
            // 
            // hours
            // 
            this.hours.Location = new System.Drawing.Point(118, 15);
            this.hours.Name = "hours";
            this.hours.Size = new System.Drawing.Size(144, 20);
            this.hours.TabIndex = 3;
            // 
            // rate
            // 
            this.rate.Location = new System.Drawing.Point(118, 40);
            this.rate.Name = "rate";
            this.rate.Size = new System.Drawing.Size(144, 20);
            this.rate.TabIndex = 4;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.rate);
            this.groupBox1.Controls.Add(this.hours);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Location = new System.Drawing.Point(32, 40);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(295, 73);
            this.groupBox1.TabIndex = 5;
            this.groupBox1.TabStop = false;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(103, 95);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(54, 13);
            this.label4.TabIndex = 5;
            this.label4.Text = "Pay Rate:";
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
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(54, 70);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(54, 13);
            this.label6.TabIndex = 7;
            this.label6.Text = "FICA Tax:";
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
            // grosstxt
            // 
            this.grosstxt.Location = new System.Drawing.Point(118, 18);
            this.grosstxt.Name = "grosstxt";
            this.grosstxt.ReadOnly = true;
            this.grosstxt.Size = new System.Drawing.Size(144, 20);
            this.grosstxt.TabIndex = 12;
            // 
            // ficatxt
            // 
            this.ficatxt.Location = new System.Drawing.Point(118, 67);
            this.ficatxt.Name = "ficatxt";
            this.ficatxt.ReadOnly = true;
            this.ficatxt.Size = new System.Drawing.Size(144, 20);
            this.ficatxt.TabIndex = 13;
            // 
            // statetxt
            // 
            this.statetxt.Location = new System.Drawing.Point(118, 116);
            this.statetxt.Name = "statetxt";
            this.statetxt.ReadOnly = true;
            this.statetxt.Size = new System.Drawing.Size(144, 20);
            this.statetxt.TabIndex = 14;
            // 
            // federaltxt
            // 
            this.federaltxt.Location = new System.Drawing.Point(118, 165);
            this.federaltxt.Name = "federaltxt";
            this.federaltxt.ReadOnly = true;
            this.federaltxt.Size = new System.Drawing.Size(144, 20);
            this.federaltxt.TabIndex = 15;
            // 
            // uniontxt
            // 
            this.uniontxt.Location = new System.Drawing.Point(118, 214);
            this.uniontxt.Name = "uniontxt";
            this.uniontxt.ReadOnly = true;
            this.uniontxt.Size = new System.Drawing.Size(144, 20);
            this.uniontxt.TabIndex = 16;
            // 
            // nettxt
            // 
            this.nettxt.Location = new System.Drawing.Point(118, 263);
            this.nettxt.Name = "nettxt";
            this.nettxt.ReadOnly = true;
            this.nettxt.Size = new System.Drawing.Size(144, 20);
            this.nettxt.TabIndex = 17;
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
            this.groupBox2.Location = new System.Drawing.Point(32, 119);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(295, 299);
            this.groupBox2.TabIndex = 18;
            this.groupBox2.TabStop = false;
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
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(19, 52);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(87, 13);
            this.label12.TabIndex = 20;
            this.label12.Text = "Employee Count:";
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
            // totalnettxt
            // 
            this.totalnettxt.Location = new System.Drawing.Point(116, 20);
            this.totalnettxt.Name = "totalnettxt";
            this.totalnettxt.ReadOnly = true;
            this.totalnettxt.Size = new System.Drawing.Size(143, 20);
            this.totalnettxt.TabIndex = 22;
            // 
            // counttxt
            // 
            this.counttxt.Location = new System.Drawing.Point(117, 49);
            this.counttxt.Name = "counttxt";
            this.counttxt.ReadOnly = true;
            this.counttxt.Size = new System.Drawing.Size(143, 20);
            this.counttxt.TabIndex = 23;
            // 
            // avgnettxt
            // 
            this.avgnettxt.Location = new System.Drawing.Point(116, 78);
            this.avgnettxt.Name = "avgnettxt";
            this.avgnettxt.ReadOnly = true;
            this.avgnettxt.Size = new System.Drawing.Size(143, 20);
            this.avgnettxt.TabIndex = 24;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.avgnettxt);
            this.groupBox3.Controls.Add(this.counttxt);
            this.groupBox3.Controls.Add(this.totalnettxt);
            this.groupBox3.Controls.Add(this.label13);
            this.groupBox3.Controls.Add(this.label12);
            this.groupBox3.Controls.Add(this.label11);
            this.groupBox3.Location = new System.Drawing.Point(34, 423);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(292, 109);
            this.groupBox3.TabIndex = 25;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Totals";
            // 
            // Calculate
            // 
            this.Calculate.Location = new System.Drawing.Point(27, 538);
            this.Calculate.Name = "Calculate";
            this.Calculate.Size = new System.Drawing.Size(96, 22);
            this.Calculate.TabIndex = 26;
            this.Calculate.Text = "&Calculate";
            this.Calculate.UseVisualStyleBackColor = true;
            this.Calculate.Click += new System.EventHandler(this.Calculate_Click);
            // 
            // Clear
            // 
            this.Clear.Location = new System.Drawing.Point(131, 538);
            this.Clear.Name = "Clear";
            this.Clear.Size = new System.Drawing.Size(96, 22);
            this.Clear.TabIndex = 27;
            this.Clear.Text = "C&lear Form";
            this.Clear.UseVisualStyleBackColor = true;
            this.Clear.Click += new System.EventHandler(this.Clear_Click);
            // 
            // Exit
            // 
            this.Exit.Location = new System.Drawing.Point(235, 538);
            this.Exit.Name = "Exit";
            this.Exit.Size = new System.Drawing.Size(96, 22);
            this.Exit.TabIndex = 28;
            this.Exit.Text = "E&xit";
            this.Exit.UseVisualStyleBackColor = true;
            this.Exit.Click += new System.EventHandler(this.Exit_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(358, 569);
            this.Controls.Add(this.Exit);
            this.Controls.Add(this.Clear);
            this.Controls.Add(this.Calculate);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "CS4 By Jared Adamson";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox hours;
        private System.Windows.Forms.TextBox rate;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox grosstxt;
        private System.Windows.Forms.TextBox ficatxt;
        private System.Windows.Forms.TextBox statetxt;
        private System.Windows.Forms.TextBox federaltxt;
        private System.Windows.Forms.TextBox uniontxt;
        private System.Windows.Forms.TextBox nettxt;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.TextBox totalnettxt;
        private System.Windows.Forms.TextBox counttxt;
        private System.Windows.Forms.TextBox avgnettxt;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Button Calculate;
        private System.Windows.Forms.Button Clear;
        private System.Windows.Forms.Button Exit;
    }
}

