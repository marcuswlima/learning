using System;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Projeto 7 - condicionais");

        int idade = 16;
        int quantidadePessoas = 2;

        if (idade >= 18)
        {
            Console.WriteLine("Pode entrar");
        }
        else
        {
            if (quantidadePessoas > 0)
            {
                Console.WriteLine("Esta acompanhado e pode entrar");
            }
            else
            {
                Console.WriteLine("Não Pode entrar");
            }

        }
        Console.WriteLine("Tecle enter para fechar");
        Console.ReadLine();

    }
}
