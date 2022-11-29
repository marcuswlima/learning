using System;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Projeto 10 ");
 
        double investimento = 1000;

//        investimento = investimento + investimento * 0.005;

        int mes = 1;

        Console.WriteLine("Inicial -> " + investimento);

        while (mes <= 12)
        {
            investimento = investimento + investimento * 0.005;
            Console.WriteLine("Mês " + mes + " terá R$" + investimento);
            mes++;
        }

        Console.WriteLine("Tecle enter para fechar");
        Console.ReadLine();
    }
}
