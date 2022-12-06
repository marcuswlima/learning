// using _05_ByteBank;

using System;

namespace ByteBank
{
    public class ContaCorrente
    {
        public Cliente Titular { get; set; }

        public static double TaxaOperacao { get; private set; } //propridade da classe e não da instancia

        public static int TotalDeContasCriadas { get; private set; } //propridade da classe e não da instancia

        public int ContadorSaquesNaoPermitidos { get; private set; }
        public int ContadorTransferenciasNaoPermitidas { get; private set; }

        //private int _agencia;
        public int Agencia { get; }
        public int Numero { get; }

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
            if (agencia <= 0)
            {
                throw new ArgumentException("O argumento agencia deve ser maior que 0.", nameof(agencia));
            }
            if (numero <= 0)
            {
                throw new ArgumentException("O argumento numero deve ser maior que 0.", nameof(numero));
            }

            Agencia = agencia;
            Numero = numero;


            try
            {
                TaxaOperacao = 30 / TotalDeContasCriadas;
            }
            catch (DivideByZeroException)
            {
                TaxaOperacao = 30;
            }

            TotalDeContasCriadas++;
        }


        public void Sacar(double valor)
        {
            if (valor < 0)
            {
                throw new ArgumentException("Valor de saque não pode ser negativo:", nameof(valor)+"|");
            }


            if (_saldo < valor)
            {
                ContadorSaquesNaoPermitidos++;
                throw new SaldoInsuficienteException(_saldo, valor);
            }

            _saldo -= valor;
        }

        public void Depositar(double valor)
        {
            _saldo += valor;
        }


        public bool Transferir(double valor, ContaCorrente contaDestino)
        {
            try
            {
                Sacar(valor);
            }
            catch (SaldoInsuficienteException)
            {
                ContadorTransferenciasNaoPermitidas++;
                throw new OperacaoFinanceiraException("Operação não realizada.");
            }
            _saldo -= valor;
            contaDestino.Depositar(valor);
            return true;
        }
    }
}
