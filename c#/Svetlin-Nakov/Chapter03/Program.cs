using System;

namespace Chapter03
{
    class Program
    {
        static void Main()
        {
            Titulo("Chapter 3. Operators and Expressions");
            Leitura();
        }

        static void Leitura()
        {
            Titulo("Arithmetical Operators");
            {
                int a, b;
                a = 5;
                b = 3;
                Console.WriteLine(a + b); // 8
                Console.WriteLine("Valor de A é {0} e valor de B é {1}", a, b);

                a = 5;
                b = 3;
                Console.WriteLine(a + (++b)); // 9
                Console.WriteLine("Valor de A é {0} e valor de B é {1}", a, b);

                a = 5;
                b = 3;
                Console.WriteLine(a + b++); // 8
                Console.WriteLine("Valor de A é {0} e valor de B é {1}", a, b);

                int one = 1;
                int zero = 0; 
                
                double dMinusOne = -1.0;
                double dZero = 0.0;
                Console.WriteLine(dMinusOne / zero); // -Infinity
                Console.WriteLine(one / dZero); // Infinity

                bool c = true;
                bool d = false;
                bool e = false;
                bool f = false;

                f = c ^ d ^ e;

                Console.WriteLine(" 2134 " + (a + b));
            }

            Titulo("Explicit Type Conversion");
            {
                double myDouble = 5.1d;
                Console.WriteLine(myDouble); // 5.1
                long myLong = (long)myDouble;
                Console.WriteLine(myLong); // 5
                myDouble = 5e9d; // 5 * 10^9
                                 //
                Console.WriteLine(myDouble); // 5000000000
                int myInt = (int)myDouble;
                Console.WriteLine(myInt); // -2147483648
                Console.WriteLine(int.MinValue); // -2147483648
            }

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
