using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace CS4
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

        private void Calculate_Click(object sender, EventArgs e)
        {
         // declare method variables 
         int hoursworked;
         int pay;
           Decimal cdecFICA_RATE;
            Decimal cdecFEDERAL_RATE; 
           Decimal cdecSTATE_RATE;
           Decimal cdecUNION_DUES;
           Decimal gross;
           Decimal ficaa;
           Decimal federala;
           Decimal statea;
           Decimal neta;
           Decimal cdecTotalNetpay;
           int cintEmployeeCount;
           Decimal decAverageNetpay;


         //Use nested try-catch blocks to get the input values 
         //so we know which one caused the error 
            try 
            {
                hoursworked = int.Parse(hours.Text);
                pay = int.Parse(rate.Text);             
                cdecFICA_RATE  = 0.06M; 
                cdecFEDERAL_RATE = 0.15M;
                cdecSTATE_RATE = 0.05M;
                cdecUNION_DUES = 10M;
                //Get pay rate from textbox 
            
                 //Calculate gross amount 
                 //Calculate taxes 
                 //Calculate net pay 
                gross = hoursworked * pay;
                ficaa = gross * cdecFICA_RATE;
                federala = gross * cdecFEDERAL_RATE;
                statea = gross * cdecSTATE_RATE;
                neta = gross - ficaa - federala - statea - cdecUNION_DUES;
                 //Accumulate summary values 
                 //Calculate average net pay 

                 //Display results of calculations and summary values
                grosstxt.Text = gross.ToString("C");
                ficatxt.Text = ficaa.ToString("C");
                statetxt.Text = statea.ToString("C");
                federaltxt.Text = federala.ToString("C");
                uniontxt.Text = cdecUNION_DUES.ToString("C");
                nettxt.Text = neta.ToString("C");


                cdecTotalNetpay = neta;
                cintEmployeeCount = 2;
                decAverageNetpay = cdecTotalNetpay / cintEmployeeCount;

                totalnettxt.Text = cdecTotalNetpay.ToString("C");
                counttxt.Text = "2";
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
        }

        private void Exit_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
