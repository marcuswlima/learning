using System;

class Program{
	
        static void Main()
        {
            Titulo("Exercicio 03");

			#region //codigo
			
			int v1, v2, v3, qdtNaoNatural;
			
			for (int i=1; i<=20; i++){
				

				v1 = IntRandom(-100,100);
				v2 = IntRandom(-100,100);
				v3 = IntRandom(-100,100);
				
				Console.Write(v1+"\t"+v2+"\t"+v3+"\t");

				qdtNaoNatural = 0;
				if (v1<0)
					qdtNaoNatural++;
				if (v2<0)
					qdtNaoNatural++;
				if (v3<0)
					qdtNaoNatural++;
				
				Console.Write(qdtNaoNatural+"\t");

				if (IsEven(qdtNaoNatural))
					Console.Write("+\n");
				else 
					Console.Write("-\n");
				
				

			}
			
			#endregion

			Console.WriteLine("");
			Console.WriteLine("************************************");
        }


		#region //randon

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
		#endregion

		#region // barra titulo

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
		#endregion

		#region //obter numero

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
		
        #region //even x odd
		static int Remainder(int divisor, int dividendo)
        {
            return divisor % dividendo;
        }

        static bool HasRemainder(int divisor, int dividendo)
        {
            return Remainder(divisor,dividendo)>0;
        }

        static bool IsEven(int numero)
        {
            return !HasRemainder(numero,2);
        }

		#endregion

}