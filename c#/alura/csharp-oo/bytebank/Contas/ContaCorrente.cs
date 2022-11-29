using System;
using System.Collections.Generic;
using System.Text;

public class ContaCorrente
{
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
        double inner_saldo = this.Saldo;

        bool resposta= (inValor <= inner_saldo);

        if (resposta)
            this.Saldo = inner_saldo - inValor;

        return resposta;
    }

    public bool Transferir(double valor, ContaCorrente destino)
    {
        bool resposta = (valor <= this.Saldo);

        if (resposta)
        {
            this.Sacar(valor);
            destino.Depositar(valor);
        }

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
    }

}
