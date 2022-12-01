using System;
using System.Collections.Generic;
using System.Text;

namespace bytebank.Operacao
{
    public class ContaCorrente
    {
        public Cliente Titular { get; set; }

        public static double TaxaOperacao { get; private set; }

        public static int TotalDeContasCriadas { get; private set; }

        private int _agencia;
        public int Agencia
        {
            get
            {
                return _agencia;
            }
            set
            {
                if (value <= 0)
                {
                    return;
                }

                _agencia = value;
            }
        }
        public int Numero { get; set; }

        private double _saldo = 100;

        public double Saldo
        {
            get
            {
                return _saldo;
            }
            set
            {
                if (value < 0)
                {
                    return;
                }

                _saldo = value;
            }
        }


        public ContaCorrente(int agencia, int numero)
        {
            Agencia = agencia;
            Numero = numero;

            TaxaOperacao = 30 / TotalDeContasCriadas;

            TotalDeContasCriadas++;
        }


        public bool Sacar(double valor)
        {
            if (_saldo < valor)
            {
                return false;
            }

            _saldo -= valor;
            return true;
        }

        public void Depositar(double valor)
        {
            _saldo += valor;
        }


        public bool Transferir(double valor, ContaCorrente contaDestino)
        {
            if (_saldo < valor)
            {
                return false;
            }

            _saldo -= valor;
            contaDestino.Depositar(valor);
            return true;
        }

        public void ToString(String mensagem)
        {
            Console.WriteLine($"***************************************");
            Console.WriteLine($"** " + mensagem);
            Console.WriteLine($"Nome Titular da conta: {this.Titular.Nome}");
            Console.WriteLine($"CPF Titular da conta: {this.Titular.CPF}");
            Console.WriteLine($"Profissão Titular da conta: {this.Titular.Profissao}");
            Console.WriteLine($"Número da Agencia: {this.Agencia}");
            Console.WriteLine($"Número da conta: {this.Numero}");
            Console.WriteLine($"Saldo R${String.Format("{0:0.00}", this.Saldo)}");
        }
    }
}
