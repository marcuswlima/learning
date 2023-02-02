using System;

namespace Chapter03
{
    class Program
    {

        //int myArraySize = 100;
        //int[] myArray;
        static void Main()
        {
            UtilTitulo("Chapter 3. Operators and Expressions");
            Leitura();
            Exercicio01();
            Exercicio02();
            Exercicio03();
            Exercicio04();
            Exercicio06();
            Exercicio07();
            Exercicio08();
            Exercicio10();
            Exercicio11();
        }

        static int Resto(int divisor, int dividendo)
        {
            return divisor % dividendo;
        }

        static bool HasRemainder(int divisor, int dividendo)
        {
            return Resto(divisor,dividendo)>0;
        }

        static bool IsOdd(int numero)
        {

            return !HasRemainder(numero,2);
        }

        static void Exercicio01()
        {
            UtilTitulo("Exercicio01");

            for (int i = 1; i <= 100; i++)
            {
                Console.Write(" "+i+"-");
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

            for (int i = 1; i <= 1000; i++)
            {
                if (!HasRemainder(i,5) && !HasRemainder(i,7))
                    Console.Write(i + " ");
            }
            Console.WriteLine("");
        }

        #region //Exercicio03
        static bool IsThirdDigitEqual7(int numero)
        {
            int semUmaCentena = numero / 100;

            return Resto(semUmaCentena, 10) == 7;
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
        #endregion

        #region //exercicio04
        static double GetTrapezoidArea(double a, double b, double h)
        {
            return (a + b) * h / 2;
        }


        static void Exercicio04()
        {
            int @max = 2;
            UtilTitulo("Exercicio04");
            for (double a = 1; a <= @max; a++)
            {
                for (double b = 1; b <= @max; b++)
                {
                    for (double h = 1; h <= @max; h++)
                    {
                        Console.WriteLine(a + " " + b + " " + h + " -> " + GetTrapezoidArea(a,b,h));
                    }
                }
            }

        }
        #endregion

        #region //Exercicio06

        static int GetRectangleArea(int b, int h)
        {
            return b * h;
        }

        static int GetRectanglePerimeter(int b, int h)
        {
            return 2*(b + h);
        }
        static int GetRectangleDiagonalSize(int b, int h)
        {
            return (b*b) + (h*h);
        }

        static void Exercicio06()
        {
            UtilTitulo("Exercicio06");
            int @max = 30;

            Console.WriteLine("a\tb\tArea\tPerimeter\tDiagonal");
            for (int b = 1; b <= @max; b++)
            {
                for (int h = 1; h <= @max; h++)
                {
                    Console.WriteLine(b + "\t" 
                                    + h + "\t"
                                    + GetRectangleArea(b,h) + "\t"
                                    + GetRectanglePerimeter(b, h) + "\t\t"
                                    + GetRectangleDiagonalSize(b, h) + "\t"
                                    );
                }
            }
        }
        #endregion

        #region //exercicio07

        static double GetWeightMoon(double weigth)
        {
            return weigth * 0.17;
        }
        static void Exercicio07()
        {
            UtilTitulo("Exercicio07");
            Console.WriteLine("Earth\tMoon");
            double weigth;
            for (int uni=80; uni<90; uni++)
            {
                for (double d = 10; d <= 100; d += 10)
                {
                    //Console.WriteLine(uni+"\t"+d+"\t"+(d / 100));
                    //Console.WriteLine(d / 100);
                    //Console.WriteLine(d);
                    weigth = uni + (d / 100);

                    Console.WriteLine(weigth + "\t" + GetWeightMoon(weigth));

                }
            }
        }
        #endregion

        #region //Exercicio08
        static void Exercicio08()
        {
            UtilTitulo("Exercicio08");

            int raio = 3;

            for (int x = -10; x <= 10; x++)
            {
                for (int y=-10; y<=10; y++)
                {
                    if ((x * x) + (y * y) <= raio * raio)
                        Console.Write("(" + x + "," + y + ") ");
//                    Console.WriteLine("Dentro");
//                    else
//                        Console.WriteLine("Fora");

                }
            }
        }
        #endregion

        #region //Exercicio10

        static void Exercicio10(int numero)
        {
            Console.WriteLine(numero);
            int u = numero % 10; 
            int d = (numero / 10) % 10; 
            int c = (numero / 100) % 10; 
            int m = (numero / 1000) % 10;
            //Console.WriteLine(m+" "+c+" "+d+" "+u);
            Console.WriteLine("Sum     = " + (m + c + d + u));
            Console.WriteLine("Reverse = " + u + d + c + m);
            Console.WriteLine("ucdm    = " + u + c + d + m);
            Console.WriteLine("mdcu    = " + m + d + c + u);
        }
        static void Exercicio10()
        {
            UtilTitulo("Exercicio10");
            int fourDigitNumber;

            fourDigitNumber = 1234;
            Exercicio10(fourDigitNumber);
            fourDigitNumber = 5678;
            Exercicio10(fourDigitNumber);
            fourDigitNumber = 9012;
            Exercicio10(fourDigitNumber);
            fourDigitNumber = 3456;
            Exercicio10(fourDigitNumber);
        }
        #endregion

        #region //Exercicio11

        static bool CheckPosition(int numero, int posicao)
        {

            int i = 1; // 00000001
            int mask = i << (posicao-1);

            if ((numero & mask) != 0)
                return true;
            else
                return false;
        }
        static void Exercicio11()
        {
            UtilTitulo("Exercicio 11 e 12");
            for (int numero = 1; numero <= 10; numero++)
            {
                for (int posicao = 1; posicao <= 8; posicao++)
                {
                    Console.WriteLine(numero + "\t" + posicao + "\t" + CheckPosition(numero,posicao));
                }
            Console.WriteLine();

            }
        }
        #endregion

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

        #region //utils
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

        #endregion
    }
}
