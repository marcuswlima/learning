using System;

class Program{
	
        static void Main()
        {
            Titulo("Exercicio 03");

			#region //codigo
			
			int v1, v2, v3, maior;
			
			for (int i=1;i<=20;i++){
				v1 = IntRandom(1,1000);
				v2 = IntRandom(1,1000);
				v3 = IntRandom(1,1000);
				
				Console.Write(v1+" "+v2+" "+v3);
				
				maior = v1;
				if (v2>maior)
					maior = v2;
				if (v3>maior)
					maior = v3;

				Console.Write(" : "+maior+"\n");

			}
			
			#endregion

			Console.WriteLine("");
			Console.WriteLine("************************************");
        }


		#region //utils

		private static Random random;

		private static void Init()
		{
		  if (random == null) random = new Random();
		}

		public static int IntRandom(int min, int max)
		{
			Init();
			return random.Next(min, max);
		}

		public static double DoubleRandom(int min, int max)
		{
			Init();
			return random.Next(min, max)+(random.Next(0, 100)/100);
		}

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