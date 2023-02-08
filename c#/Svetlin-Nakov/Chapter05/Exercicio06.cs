using System;

class Program{
	
        static void Main()
        {
            Titulo("Exercicio 06");
			

			#region //codigo
			int a,b,c;
			string mensagem;
			
			Console.Write("a\tb\tc\td\tRealRoots\n");
			for (int i=1; i<=15; i++){
				a = IntRandom(1,3);
				b = IntRandom(1,10);
				c = IntRandom(1,1);

				Console.Write(a+"\t"+b+"\t"+c+"\t");
				
				RealRoots(a,b,c,out mensagem);

				Console.Write(mensagem+"\t");

				Console.Write("\n");
				
			}
			#endregion

			Console.WriteLine("");
			Console.WriteLine("************************************");
        }
		
		#region //quadratic equation
		static int Discriminant(int a, int b, int c){
			return (b*b) - (4*a*c);
		}
		static void RealRoots(int a, int b, int c, out string mensagem){
			int d=Discriminant(a,  b, c);
			mensagem=" ";
			
			if (d<0)
				mensagem=d+"\t"+"no real roots";
			else
				if (d==0)
					mensagem=(d+"\t"+(-1)*b/(a*2))+"\t";
				else
					mensagem=(d+"\t"+
							 (((-1)*b)+(Math.Sqrt(d)) / (2*a)) + "\t" 
						   + (((-1)*b)-(Math.Sqrt(d)) / (2*a)) + "\t"
							 );
		}
		#endregion
		
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
			return random.Next(min, max+1);
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