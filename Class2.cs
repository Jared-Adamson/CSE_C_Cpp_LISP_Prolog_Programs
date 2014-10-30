using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CS8
{
    class clsOrderPreferred : clsOrder
    {
        private const decimal cdecDISCOUNT_RATE = 0.05M;

        //declare default constructor - call base default constructor
        
        //declare overloaded constructor - call base overloaded constructor

        //override definition of virtual definition in base
        public override void calcExtendedPrice()
        {
            cdecExtendedPrice = cintQuantity *
                (cdecPrice - cdecPrice * cdecDISCOUNT_RATE);
        }
    }//end of class
}//end of class
