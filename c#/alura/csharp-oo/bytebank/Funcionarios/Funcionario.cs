using System;
using System.Collections.Generic;
using System.Text;

namespace bytebank.Funcionarios
{
    public abstract class Funcionario //abostrata - classe que não deverá ser instanciada
    {
        public string Nome { get; set; }
        public string Cpf { get; private set; }
        public double Salario { get; protected set; }

        //private int tipo;//0-Funcionario;1-Diretor;2-analista

        public static int TotalDeFuncionarios { get; private set; } //o atributo passa a ser da classe e não do objeto

        public abstract double GetBonificacao(); //a implementação do atributo passa a ser da classe derivada e é obrigatória

        public abstract void AumentarSalario();//a implementação do atributo passa a ser da classe derivada e é obrigatória

        public Funcionario(string cpf, double salario)
        { 
            this.Cpf = cpf;
            this.Salario = salario;
            TotalDeFuncionarios++;
            //Console.WriteLine("Criando um funcionario - base");
        }

    }
}
