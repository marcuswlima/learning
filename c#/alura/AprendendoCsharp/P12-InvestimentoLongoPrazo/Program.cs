using System;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Projeto 12 investimento longo prazo");

        double fatoRendimento = 1.005, investimento=1000;


        for (int anos=1; anos <= 5; anos++)
        {
            for (int mes = 1; mes <= 12; mes++)
            {
                investimento *= fatoRendimento;
            }
            fatoRendimento += 0.001;
        }

        Console.WriteLine("Depois de 5 anoes "+ investimento);

        Console.WriteLine("Tecle enter para fechar");
        Console.ReadLine();
    }
}
