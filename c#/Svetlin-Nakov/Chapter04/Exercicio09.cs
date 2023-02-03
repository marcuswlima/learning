using System;

class Program{
	
        static void Main()
        {
            Titulo("Exercicio 09");

			#region //codigo
			int quantNumeros = ObterPositivo("Informe um número positivo para a quantidade: "),
			    quantDigitados=1,
				soma=0,
				informado;
			
			do
			{
				informado = ObterInteiro("Informa um nùmero("+quantDigitados+"): ");
				soma += informado;
				quantDigitados++;
			}while (quantDigitados <= quantNumeros);
			Console.WriteLine("A soma dos numeros digitados e: "+soma);
			#endregion

			Console.WriteLine("");
			Console.WriteLine("************************************");
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