using System;

class Program{
	
        static void Main()
        {
            Titulo("Exercicio 07");

			#region //codigo
			int num1,num2,num3,num4,num5;

			num1=ObterNumero("Informe o primeiro número: ");
			num2=ObterNumero("Informe o segundo número: ");
			num3=ObterNumero("Informe o terceiro número: ");
			num4=ObterNumero("Informe o quarto número: ");
			num5=ObterNumero("Informe o quinto número: ");
			Console.WriteLine(num1+"+"+num2+"+"+num3+"+"+num4+"+"+num5+"="+(num1+num2+num3+num4+num5));
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

		static int ObterNumero(string mensagem){
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
		#endregion

}