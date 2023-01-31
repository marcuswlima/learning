using System;
using System.Globalization;

namespace Chapter01
{
    class Chapter01
    {
        static void Main()
        {
            Titulo("Exercicio 07");
            Console.WriteLine("1");
            Console.WriteLine("101");
            Console.WriteLine("1001");

            Titulo("Exercicio 08");
            DateTime localDate = DateTime.Now;
            DateTime utcDate = DateTime.UtcNow;
            String[] cultureNames = { "en-US", "en-GB", "fr-FR",
                                "de-DE", "pt-BR", "sp-SP"  };

            foreach (var cultureName in cultureNames)
            {
                var culture = new CultureInfo(cultureName);
                Console.WriteLine("{0}:", culture.NativeName);
                Console.WriteLine("   Local date and time: {0}, {1:G}",
                                  localDate.ToString(culture), localDate.Kind);
                Console.WriteLine("   UTC date and time: {0}, {1:G}\n",
                                  utcDate.ToString(culture), utcDate.Kind);
            }


            Titulo("Exercicio 09 - square root of 12345.");
            Console.WriteLine(Math.Sqrt(12345));

            Titulo("Exercicio 10");

            for (int i = 1; i <= 100 ; i++)
            {
                Console.Write(i);
                Console.Write(" ");
            }
            Console.WriteLine(" ");

            Titulo("Exercicio 11");

            Console.Write("Informe a sua idade: ");
            String informado = Console.ReadLine();
            int numVal = Int32.Parse(informado)+10;
            Console.Write("A sua idade após 10 anos será: ");
            Console.WriteLine(numVal);

            Titulo("Exercicio 12");

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
            Console.WriteLine("** "+titulo+ " **");
            ImprimeBarra(titulo);

        }
    }
}
