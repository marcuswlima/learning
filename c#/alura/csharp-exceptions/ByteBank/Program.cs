using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ByteBank
{
    class Program
    {
        static int Dividir(int numero, int divisor)
        {
            ContaCorrente conta = null;
            Console.WriteLine(conta.Saldo);
            return numero / divisor;
        }

        static void TestaDivisao(int divisor)
        {
            Dividir(10, divisor);
        }

        static void Metodo()
        {
            TestaDivisao(1);
        }

        static void Main(string[] args)
        {

            try
            {
                ContaCorrente conta1 = new ContaCorrente(4564, 789684);
                ContaCorrente conta2 = new ContaCorrente(7891, 456794);

                //conta1.Sacar(10000);
                Console.WriteLine(conta1.Saldo);
                Console.WriteLine(conta2.Saldo);
                conta2.Transferir(1, conta1);
                Console.WriteLine(conta1.Saldo);
                Console.WriteLine(conta2.Saldo);
            }
            catch (ArgumentException ex)
            {
                Console.WriteLine("erro de ArgumentException");
                Console.WriteLine(ex);
            }
            catch (SaldoInsuficienteException ex)
            {
                Console.WriteLine("erro de SaldoInsuficienteException-> ");
                Console.WriteLine(ex);
            }
            catch (OperacaoFinanceiraException e)
            {
                Console.WriteLine(e.Message);
                Console.WriteLine(e.StackTrace);

                Console.WriteLine("Informações da INNER EXCEPTION (exceção interna):");

                Console.WriteLine(e.InnerException.Message);
                Console.WriteLine(e.InnerException.StackTrace);
            }

            //**********************************
            Console.WriteLine("**********************************");
            Console.WriteLine("Digite qualquer tecla para sair");
            Console.ReadLine();
        }
    }
}
