using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace CS5
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
        // Class  scope variables 
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
            int hoursworked;
            int pay;
            Decimal gross;
            Decimal ficaa;
            Decimal federala;
            Decimal statea;
            Decimal neta;

            cintEmployeeCount = 0 + cintEmployeeCount;
           

            //Use nested try-catch blocks to get the input values 
            //so we know which one caused the error 

           

            try
            {
                hoursworked = int.Parse(hours.Text);
                pay = int.Parse(rate.Text);
                cdecFICA_RATE = 0.06M;
                cdecFEDERAL_RATE = 0.15M;
                cdecSTATE_RATE = 0.05M;

               
                //Get pay rate from textbox 
                //Calculate net pay 
                if (hoursworked <= 40)
                    gross = hoursworked * pay;
                else
                    gross = (40 * pay) + ((hoursworked - 40) * pay * 1.5M);
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
                // Rates
                ficaa = gross * cdecFICA_RATE;
                federala = gross * cdecFEDERAL_RATE;
                statea = gross * cdecSTATE_RATE;
                neta = gross - ficaa - federala - statea - cdecUNION_DUES;
             

                if (pay > 9 && pay < 16)
                   
                  {
                          

                       }
                       else
                       {
                            MessageBox.Show("Pay Rate must be between $10.00 and $15.00. ", 
                                "Data Entry Error", MessageBoxButtons.OK, 
                                MessageBoxIcon.Exclamation);
                            
                       }
                if (hoursworked > 0 && hoursworked < 50)
                {

                }
                else
                {
                    MessageBox.Show("Hours must be between 1 and 50. ",
                        "Data Entry Error", MessageBoxButtons.OK,
                        MessageBoxIcon.Exclamation);

                }
                


                //Display results of calculations and summary values
                grosstxt.Text = gross.ToString("C");
                ficatxt.Text = ficaa.ToString("C");
                statetxt.Text = statea.ToString("C");
                federaltxt.Text = federala.ToString("C");
                uniontxt.Text = cdecUNION_DUES.ToString("C");
                nettxt.Text = neta.ToString("C");


                cdecTotalNetpay = neta;
                cintEmployeeCount += 1;
                decAverageNetpay = cdecTotalNetpay / cintEmployeeCount;
                 
                totalnettxt.Text = cdecTotalNetpay.ToString("C");
                counttxt.Text = cintEmployeeCount.ToString("N");
                avgnettxt.Text = decAverageNetpay.ToString("C");



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

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
