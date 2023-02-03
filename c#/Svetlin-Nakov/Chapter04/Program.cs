using System;

namespace Chapter04
{
    class Program
    {
        static void Main()
        {
            Titulo("Chapter 4. Console Input and Output");
            Console.WriteLine("Hello World!");
            Leitura();
        }

        static void Leitura()
        {
            Console.WriteLine(Console.In);//, Console.Out, and Console.Error
            Console.WriteLine(Console.Out);
            Console.WriteLine(Console.Error);
            Console.WriteLine("{1} is {0} years old from {3}!", 18, "John", 0, "Seattle","asdft");
            Console.WriteLine("{0,6}", 123);
            Console.WriteLine("{0,6}", 1230);
            Console.WriteLine("{0:X}", 11);
            Console.WriteLine("{0:C2}", 123.456);
            Console.WriteLine("{0:0000.0000}",123.456);
            Console.WriteLine("{0:(00)0-0000-0000}",91984117417);
            DateTime d = new DateTime(2012, 02, 27, 17, 30, 22);
            Console.WriteLine(d);
            Console.WriteLine("{0:d}",d);
            //Console.WriteLine(DayOfWeek+1);

            int a=1, b=2;
            TesteMetodo(a, out b);
            Console.WriteLine(b);
        }

        static void TesteMetodo(int a, out int b)
        {
            b = a;
        }


        #region //utils
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

        #endregion
    }
}
