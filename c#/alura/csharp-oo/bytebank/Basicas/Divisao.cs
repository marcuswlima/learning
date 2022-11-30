using System;
using System.Collections.Generic;
using System.Text;

namespace bytebank.Basicas
{
    public class Divisao
    {
        public double Calcular(double dividendo, double divisor)
        {
            if (divisor == 0)
            {
                return 0;
            }
            return dividendo / divisor;
        }
    }
}
