using System;

class Program{
	
        static void Main()
        {
            Titulo("Exercicio 11");

			#region //codigo
			
			Console.WriteLine(Fibonacci(0));
			Console.WriteLine(Fibonacci(1));
			Console.WriteLine(Fibonacci(2));
			Console.WriteLine(Fibonacci(3));
			Console.WriteLine(Fibonacci(4));
			Console.WriteLine(Fibonacci(19));
/*			

			int anterior=0;
			Console.WriteLine(anterior+" / ");
			for (int n=1;n<=5;n++){
				Console.Write("anterior->"+anterior);
				Console.Write(" n->"+n);
				//int resultado = anterior+n;
				Console.WriteLine(" / ");
				anterior=n;
			}
*/
			#endregion

			Console.WriteLine("");
			Console.WriteLine("************************************");
        }

		static int Fibonacci(int numero){
			if (numero==0)
				return 0;
			else if (numero==1)
				return 1;
			else 
				return Fibonacci(numero-1)+Fibonacci(numero-2);
		}

		#region //utils
        static void ImprimeBarra(String titulo)
        {
            int tamanho = titulo.Length;

            for (int i = 1; i <= tamanho + 6; i++)
            {
                Console.Write("*");
            }

            Console.WriteLine(" ");
        }

        static void Titulo(String titulo)
        {
            Console.WriteLine(" ");

            ImprimeBarra(titulo);
            Console.WriteLine("** " + titulo + " **");
            ImprimeBarra(titulo);

        }

		static int ObterInteiro(string mensagem){
			bool parseSuccess = false;
			string str;
			int resposta;
			do{
				Console.Write(mensagem);
				str = Console.ReadLine();
				parseSuccess = Int32.TryParse(str, out resposta);
			}while (parseSuccess == false);
			return resposta;
		}
		
		static int ObterPositivo(string mensagem){
			int temp;
			do{
				temp = ObterInteiro(mensagem);
			}while (temp<=0);
			return temp;
		}
		
		#endregion

}