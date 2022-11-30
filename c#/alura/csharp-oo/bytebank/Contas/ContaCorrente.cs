using System;
using System.Collections.Generic;
using System.Text;

public class ContaCorrente
{
    public static int TotalContasCriadas { get; private set; }
    public double Saldo { get; set; }
    public int Agencia { get; set; }
    public string Conta { get; set;}
    public Cliente Titular { get; set; }

    public void Depositar(double inValor)
    {
        this.Saldo += inValor;
    }

    public bool Sacar(double inValor)
    {

        bool resposta = (inValor <= this.Saldo);

        if (resposta)
            this.Saldo -= inValor;
        else
            Console.WriteLine("Não fez o saque");


        return resposta;
    }

    public bool Transferir(double valor, ContaCorrente destino)
    {
        bool resposta = this.Sacar(valor);

        if (resposta)
            destino.Depositar(valor);
        else
            Console.WriteLine("Transferencia não realizada");

        return resposta;
    }
    
    public void ToShow(String mensagem)
    {
        Console.WriteLine($"***************************************");
        Console.WriteLine($"** " + mensagem);
        Console.WriteLine($"Nome Titular da conta: {this.Titular.Nome}");
        Console.WriteLine($"CPF Titular da conta: {this.Titular.Cpf}");
        Console.WriteLine($"Profissão Titular da conta: {this.Titular.Profissao}");
        Console.WriteLine($"Número da Agencia: {this.Agencia}");
        Console.WriteLine($"Número da conta: {this.Conta}");
        Console.WriteLine($"Saldo R${String.Format("{0:0.00}", this.Saldo)}");
    }

    public ContaCorrente(int inAgencia, string inConta, string inNome)
    {
        this.Agencia = inAgencia;
        this.Conta = inConta;
        this.Titular = new Cliente(inNome);
        this.Saldo = 100;
        TotalContasCriadas++;
    }

}
