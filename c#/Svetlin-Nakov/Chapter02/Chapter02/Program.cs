using System;

namespace Chapter02
{
    class Program
    {
        static void Main()
        {
            Titulo("Exercicio 01");
            {
                //float @float = 52.130f; //52,130;
                sbyte @sbyte = -115;    //-115;
                uint @uint = 4825932;
                byte @byte = 97;        //97
                short @short = -10000;  //-10000;
                ushort @ushort = 20000; //20000;
                byte byte2 = 224;       //224
                int @int = 970700000;   //970,700,000; 
                sbyte @sbyte2 = 112;    //112; 
                sbyte @sbyte3 = -44;    //-44; 
                int @int2 = -1000000;   //-1,000,000; 
                ushort @ushort2 = 1990;//1990; 
                ulong @long = 123456789123456789;//123456789123456789             
            }

            Titulo("Exercicio 02");
            {
                float @float = 5;
                double @double = 5;
                decimal @decimal = 5;

                float @float2 = 5.01F;
                double @double2 = 5.01d;
                decimal @decimal2 = 5.01m;

                float @float3 = 34.567839023f;
                double @double3 = 34.567839023d;
                decimal @decimal3 = 34.567839023m;

                float @float4 = 12.345f;
                double @double4 = 12.345d;
                decimal @decimal4 = 12.345m;

                float @float5 = 8923.1234857F;
                double @double5 = 8923.1234857d;
                decimal @decimal5 = 8923.1234857M;

                float @float6 = 3456.091124875956542151256683467F;
                double @double6 = 3456.091124875956542151256683467d;
                decimal @decimal6 = 3456.091124875956542151256683467M;
            }

            Titulo("Exercicio 03");
            {
                decimal a, b;
                a = 0.000001m;
                b = 0.000001m;

                bool equal = Math.Abs(a - b) < 0.000001m;

                Console.WriteLine(equal);
            }

            Titulo("Exercicio 04");
            {
                int var = 0x100;
                Console.WriteLine(var);
                var = 0xA0A;
                Console.WriteLine(var);
            }

            Titulo("Exercicio 05");
            {
                char character = '\u003A';
                Console.WriteLine(character);
                character = '\u00A3';
                Console.WriteLine(character);
            }

            Titulo("Exercicio 07 e 08");
            {
                string st1 = "Hello", 
                       st2 = "World" ;
                object @object = st1 + " " + st2;

                Console.WriteLine(@object);

                string str3 = (string)@object;

                Console.WriteLine(str3);
            }

            Titulo("Exercicio 09");
            {
                string strE09 = "The \"use\" of quotations causes difficulties.";
                Console.WriteLine(strE09);
                strE09 = "The \"use\" of quotations causes difficulties.";
                Console.WriteLine(strE09);
            }

            Titulo("Exercicio 10");
            {
                Console.WriteLine(" ** **");
                Console.WriteLine("*  *  *");
                Console.WriteLine(" *   * ");
                Console.WriteLine("  * *");
                Console.WriteLine("   *");
            }

            Titulo("Exercicio 11");
            {
                Console.WriteLine(Console.OutputEncoding);
                char caracter11 = '\u00A9';
                Console.WriteLine(caracter11);
            }

            Titulo("Exercicio 12");
            {
                int uniqueEmployee;
                string firstName;
                string lastName;
                byte age;
                char gender;
            }

            Titulo("Exercicio 13");
            {
                int aE13, bE13, oldA;

                aE13 = 7;
                bE13 = 8989;

                Console.WriteLine("Valor de A " + aE13 + " e o valor de B: "+ bE13);


                oldA = aE13;
                aE13 = bE13;
                bE13 = oldA;

                Console.WriteLine("Valor de A " + aE13 + " e o valor de B: " + bE13);
            }
        }

        static void Leitura()
        {

            // Declare some variables
            byte centuries = 20;
            ushort years = 2000;
            uint days = 730480;
            ulong hours = 17531520;

            // Print the result on the console
            Console.WriteLine(centuries + " centuries are "
                            + years + " years, or "
                            + days + " days, or "
                            + hours + " hours.");

            // Console output: // 20 centuries are 2000 years, or 730480 days, or 17531520 // hours.
            ulong maxIntValue = UInt64.MaxValue;
            Console.WriteLine(maxIntValue);
            // 18446744073709551615

            //float MinFloat = float.MinValue;
            Console.WriteLine(float.MinValue);
            Console.WriteLine(float.MaxValue);

            //double MinDouble = Double.MinValue;
            Console.WriteLine(Double.MinValue);
            Console.WriteLine(Double.MaxValue);

            float floatPI = 3.141592653589793238f;
            double doublePI = 3.141592653589793238D;

            Console.WriteLine("Float PI is: " + floatPI);
            Console.WriteLine("Double PI is: " + doublePI);

            float f = 0.1f;
            Console.WriteLine(f); // 0.1 (correct due to rounding)
            double d = 0.1f;
            Console.WriteLine(d); // 0.100000001490116 (incorrect)
            Console.WriteLine("********************");

            char ch;
            for (int i = 1; i <= 2000; i++)
            {
                ch = (char)i;
                Console.Write(i);
                Console.Write("-");
                Console.Write(ch);
                Console.Write(" ");

            }

            bool @bool;

            //@bool = false;
        }

        static void ImprimeBarra(String titulo)
        {
            int tamanho = titulo.Length;

            for (int i = 1; i <= tamanho + 6; i++)
            {
                Console.Write("*");
            }

            Console.WriteLine(" ");
        }

        static void Titulo(String titulo)
        {
            Console.WriteLine(" ");

            ImprimeBarra(titulo);
            Console.WriteLine("** " + titulo + " **");
            ImprimeBarra(titulo);

        }

    }
}
