using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace CS6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            rate.Text = "0";
            hours.Text = "0";
            grosstxt.Text = "0";
            ficatxt.Text = "0";
            statetxt.Text = "0";
            federaltxt.Text = "0";
            uniontxt.Text = "0";
            nettxt.Text = "0";
            totalnettxt.Text = "0";
            counttxt.Text = "0";
            avgnettxt.Text = "0";
        }
        Decimal cdecFICA_RATE;
        Decimal cdecFEDERAL_RATE;
        Decimal cdecSTATE_RATE;
        Decimal cdecUNION_DUES;
        int cintEmployeeCount;
        Decimal cdecTotalNetpay;
        Decimal decAverageNetpay;
        private void Calculate_Click(object sender, EventArgs e)
        {
             // declare method variables 
            int IntHoursWorked;
            int IntPay;
            Decimal DecGross;
            Decimal DecFicaa;
            Decimal DecFederal;
            Decimal DecState;
            Decimal DecNet;

         
           

            //Use nested try-catch blocks to get the input values 
            //so we know which one caused the error 

           

            try
            {
                IntHoursWorked = int.Parse(hours.Text);
                IntPay = int.Parse(rate.Text);
                cdecFICA_RATE = 0.06M;
                cdecFEDERAL_RATE = 0.15M;
                cdecSTATE_RATE = 0.05M;
                cintEmployeeCount = 0 + cintEmployeeCount;

                if (IntHoursWorked <= 40)
                    DecGross = IntHoursWorked * IntPay;
                else
                    DecGross = (40 * IntPay) + ((IntHoursWorked - 40) * IntPay * 1.5M);
                if (RADreg.Checked == true)
                {
                    cdecUNION_DUES = 5.00M;
                }
                else if (RADspec.Checked == true)
                {

                    cdecUNION_DUES = 10.00M;
                }
                else
                {
                    cdecUNION_DUES = 0.00M;
                }
                DecFicaa = DecGross * cdecFICA_RATE;
                DecFederal = DecGross * cdecFEDERAL_RATE;
                DecState = DecGross * cdecSTATE_RATE;
                DecNet = DecGross - DecFicaa - DecFederal - DecState - cdecUNION_DUES;
                if (IntPay > 9 && IntPay < 16)
                    if (IntHoursWorked > 0 && IntHoursWorked < 51)
                    {
                        //Display results of calculations and summary values
                        grosstxt.Text = DecGross.ToString("C");
                        ficatxt.Text = DecFicaa.ToString("C");
                        statetxt.Text = DecState.ToString("C");
                        federaltxt.Text = DecFederal.ToString("C");
                        uniontxt.Text = cdecUNION_DUES.ToString("C");
                        nettxt.Text = DecNet.ToString("C");


                        cdecTotalNetpay = DecNet;
                        cintEmployeeCount += 1;
                        decAverageNetpay = cdecTotalNetpay / cintEmployeeCount;

                        totalnettxt.Text = cdecTotalNetpay.ToString("C");
                        counttxt.Text = cintEmployeeCount.ToString("N");
                        avgnettxt.Text = decAverageNetpay.ToString("C");

                    }
                    else
                    {
                        MessageBox.Show("Hours must be between 1 and 50. ",
                          "Data Entry Error", MessageBoxButtons.OK,
                          MessageBoxIcon.Exclamation);
                    }
              
                else
                {
                    MessageBox.Show("Pay Rate must be between $10.00 and $15.00. ",
                            "Data Entry Error", MessageBoxButtons.OK,
                            MessageBoxIcon.Exclamation);
                    
                }
                //Get IntPay rate from textbox 
                //Calculate net IntPay 
               
                // Rates
               
             

                          



            }
            
            catch (FormatException err)
            {
                MessageBox.Show("Pay Rate must be numeric. " + err.Message,
                  "Data Entry Error", MessageBoxButtons.OK,
                  MessageBoxIcon.Exclamation);
                rate.SelectAll();
                rate.Focus();
            }

        
        }

        private void Clear_Click(object sender, EventArgs e)
        {
            rate.Text = "0";
            hours.Text = "0";
            grosstxt.Text = "0";
            ficatxt.Text = "0";
            statetxt.Text = "0";
            federaltxt.Text = "0";
            uniontxt.Text = "0";
            nettxt.Text = "0";
            totalnettxt.Text = "0";
            counttxt.Text = "0";
            avgnettxt.Text = "0";
            cdecTotalNetpay = 0;
            cintEmployeeCount = 0;
        }

        private void Exit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
      Exit_Click(sender, e);
        }

        private void clearFormToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Clear_Click(sender, e);
        }

        private void calculateToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Calculate_Click(sender, e);
        }
        
       
        private void fontToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FontDialog fontDialog1 = new FontDialog();
            fontDialog1.ShowColor = true;
            //Use the current settings as the default in the dialog box
            fontDialog1.Font = totalnettxt.Font;

            //Display dialog box so user can pick a font
            //Apply the font chosen to the Totals section if not Canceled
            if (fontDialog1.ShowDialog() != DialogResult.Cancel)
            {
                totalnettxt.Font = fontDialog1.Font;
                counttxt.Font = fontDialog1.Font;
                avgnettxt.Font = fontDialog1.Font;
            }
        }
        
        private void colorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Make Color Dialog
            ColorDialog colorDialog1 = new ColorDialog();
         
            //Apply Color
            if (colorDialog1.ShowDialog() != DialogResult.Cancel)
            
                totalnettxt.ForeColor = colorDialog1.Color;
                counttxt.ForeColor = colorDialog1.Color;
                avgnettxt.ForeColor = colorDialog1.Color;
            

           
        }
        
    }
}
