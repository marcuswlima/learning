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
            //Console.WriteLine(conta.Saldo);
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
                ContaCorrente conta = new ContaCorrente(10, 10);
                conta.Depositar(50);
                Console.WriteLine(conta.Saldo);
                conta.Sacar(500);
                Console.WriteLine(conta.Saldo);
            }
            catch (ArgumentException ex)
            {
                Console.WriteLine("erro de ArgumentException"+ex);
                //Console.WriteLine(ex.Message);
                //Console.WriteLine(ex.StackTrace);
                //Console.WriteLine(ex.ParamName);
            }
            catch (DivideByZeroException excecao)
            {
                //Console.WriteLine("Divisão por zero tratado");
                Console.WriteLine("***** Message");
                Console.WriteLine(excecao.Message);
                Console.WriteLine("***** StackTrace");
                Console.WriteLine(excecao.StackTrace);
            }
            catch (SaldoInsuficienteException ex)
            {
                Console.WriteLine("erro de SaldoInsuficienteException: ");
                Console.WriteLine(ex);
            }

            /*
                        try
                        {
                            Metodo();
                        }
                        catch (DivideByZeroException excecao)
                        {
                            //Console.WriteLine("Divisão por zero tratado");
                            Console.WriteLine("***** Message");
                            Console.WriteLine(excecao.Message);
                            Console.WriteLine("***** StackTrace");
                            Console.WriteLine(excecao.StackTrace);
                        }
                        catch (NullReferenceException excecao)
                        {
                            //Console.WriteLine("Divisão por zero tratado");
                            Console.WriteLine("***** Message");
                            Console.WriteLine(excecao.Message);
                            Console.WriteLine("***** StackTrace");
                            Console.WriteLine(excecao.StackTrace);
                        }
            */

            //**********************************
            Console.WriteLine("**********************************");
            Console.WriteLine("Digite qualquer tecla para sair");
            Console.ReadLine();
        }
    }
}
