using System;

class Program{
	
        static void Main()
        {
            Titulo("Exercicio 05");
			

			#region //codigo
			int randomizado=0;
			for (int i=1;i<=100;i++){
				randomizado = IntRandom(1,11);
				Console.Write(randomizado+"-"+NumeroExtenso(randomizado)+" ");
			}
			#endregion

			Console.WriteLine("");
			Console.WriteLine("************************************");
        }
		
		#region //numeroExtenso
		static string NumeroExtenso(int numero){
			string resposta;
			switch (numero)
			{
				case 1:resposta="um"    ;break;
				case 2:resposta="dois"  ;break;
				case 3:resposta="tres"  ;break;
				case 4:resposta="quatro";break;
				case 5:resposta="cinco" ;break;
				case 6:resposta="seis"  ;break;
				case 7:resposta="sete"  ;break;
				case 8:resposta="oito"  ;break;
				case 9:resposta="nove"  ;break;
				default:resposta="Unknown"; break;			
			}
			return resposta;
		}
		#endregion

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
		static int ObterInteiroNaFaixa(string mensagem,int menor, int maior){
			int numero=0;
			do{
				numero = ObterInteiro(mensagem + "["+menor+":"+maior+"]: ");
			}while ((numero<menor)||(numero>maior));
			return numero;
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