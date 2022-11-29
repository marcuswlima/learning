using System;

class Programa
{
    static void Main(string[] args)
    {

        // Ate 1900.0 o IR é de 7.5% e pode deduzir R$ 142
        // De 1900.01 até 2800.0 o IR é de 7.5% e pode deduzir R$ 142
        // De 2800.01 até 3751.0 o IR é de 15% e pode deduzir R$ 350
        // De 3751.01 até 4664.00 o IR é de 22.5% e pode deduzir R$ 636
        // De mair que 4664.01 o IR é de 27.5% e pode deduzir R$ 700

        double salario = 3000.0;
        double ir, deducao;

        if (salario < 1900)
        {
            ir = 0;
            deducao = 0;
        } else if (salario > 1900.01 && salario < 2800)
        {
            ir = 7.5;
            deducao = 143;
        }
        else if (salario > 2800.01 && salario < 3751)
        {
            ir = 15;
            deducao = 350;
        }
        else if (salario > 3751.01 && salario < 4664.00)
        {
            ir = 22.5;
            deducao = 636;
        }
        else 
        {
            ir = 27.5;
            deducao = 700;
        }

        Console.WriteLine("Salario -> " + salario);
        Console.WriteLine("IR -> " + ir);
        Console.WriteLine("deducao -> " + deducao);
        Console.WriteLine("Tecle enter para fechar");
        Console.ReadLine();
    }
}