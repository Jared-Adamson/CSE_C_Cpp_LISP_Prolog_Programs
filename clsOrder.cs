using System;
using System.Collections.Generic;
using System.Text;

//clsOrder by Your Name

namespace CS8
{
    class clsOrder
    {
        //declare class variables include shared (static)
        public string cstrDescription;
        public int cintQuantity;
        public decimal cdecPrice;
        public decimal cdecExtendedPrice;
       public static decimal cdecTotalPrice;
       public static int cintTotalCount;

         
        //declare constructors

        //declare property methods

        //declare read-only properties
       public virtual decimal ExtendedPrice
        {
            get
            {
                return  cdecExtendedPrice;
            }
        }

        //declare Shared (static) ReadOnly Properites
        public static decimal TotalPrice
        {
            get
            {
                return cdecTotalPrice;
            }
        }

        public static int TotalCount
        {
            get
            {
                return cintTotalCount;
            }
        }

        //declare supporting methods
        public virtual void calcExtendedPrice()
        {
             cdecExtendedPrice = cintQuantity * cdecPrice;
        }

        public void accumulateTotals()
        {
            cdecTotalPrice += cdecExtendedPrice;
            cintTotalCount += 1;
        }

        public static void resetTotals()
        {
            cdecTotalPrice = 0;
            cintTotalCount = 0;
        }

    }//end of class

}