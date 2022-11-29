using System;

namespace _4_Conversoes
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Executendo o projeto simples");

            char letra = 'a';
            Console.WriteLine(letra);

            letra = (char)65;
            Console.WriteLine(letra);

            letra = (char)(65+1);
            Console.WriteLine(letra);

            letra = (char)(86 + 1);
            Console.WriteLine(letra);

            string primeiraFrase = "Alura cursos de tecnologia ";
            Console.WriteLine(primeiraFrase + 2022);

            Console.WriteLine("Tecle enter para fechar");
            Console.ReadLine();


        }
    }
}
