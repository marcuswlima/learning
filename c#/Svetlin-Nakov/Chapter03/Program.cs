using System;

namespace Chapter03
{
    class Program
    {

        int myArraySize = 100;
        int[] myArray;
        static void Main()
        {
            UtilTitulo("Chapter 3. Operators and Expressions");
            Leitura();
            Exercicio01();
            Exercicio02();
            Exercicio03();
        }

        static int Remainder(int divisor, int dividendo)
        {
            return divisor % dividendo;
        }

        static bool HasRemainder(int divisor, int dividendo)
        {
            return Remainder(divisor,dividendo)>0;
        }

        static bool IsOdd(int numero)
        {

            return !HasRemainder(numero,2);
        }

        static bool IsThirdDigitEqual7(int numero)
        {
            int semUmaCentena = numero / 100;

            return Remainder(semUmaCentena, 10)==7;
        }

        static void Exercicio01()
        {
            UtilTitulo("Exercicio01");

            for (int i = 1; i <= 100; i++)
            {
                Console.Write(" "+i+"->");
                if (IsOdd(i))
                    Console.Write("Par");
                else
                    Console.Write("Impar");
            }
            Console.WriteLine("");


        }

        static void Exercicio02()
        {
            UtilTitulo("Exercicio02");

            for (int i = 1; i <= 100; i++)
            {
                if (!HasRemainder(i,5) && !HasRemainder(i,7))
                    Console.Write(i + " ");
            }
            Console.WriteLine("");
        }

        static void Exercicio03()
        {
            UtilTitulo("Exercicio03");
            for (int i = 100; i <= 10000; i++)
            {
                if (IsThirdDigitEqual7(i))
                    Console.Write(i + " ");
            }
            Console.WriteLine("");
        }

        static void Leitura()
        {
            UtilTitulo("Arithmetical Operators");
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

            UtilTitulo("Explicit Type Conversion");
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

        static void UtilImprimeBarra(String titulo)
        {
            int tamanho = titulo.Length;

            for (int i = 1; i <= tamanho + 6; i++)
            {
                Console.Write("*");
            }

            Console.WriteLine(" ");
        }

        static void UtilTitulo(String titulo)
        {
            Console.WriteLine(" ");

            UtilImprimeBarra(titulo);
            Console.WriteLine("** " + titulo + " **");
            UtilImprimeBarra(titulo);

        }
    }
}
