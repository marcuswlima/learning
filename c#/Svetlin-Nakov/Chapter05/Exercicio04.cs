using System;

class Program{
	
        static void Main()
        {
            Titulo("Exercicio 04");

			#region //codigo
			
			int r1, r2, r3, o1=0, o2=0, o3=0;
			
			for (int i=1; i<=10; i++){
				

				r1 = IntRandom(-100,100);
				r2 = IntRandom(-100,100);
				r3 = IntRandom(-100,100);
				
				Console.Write(r1+"\t"+r2+"\t"+r3+"\n");
				
				
				if ((r1>r2)&&(r1>r3)){
					o1=r1;
					if (r2>r3){
						o2=r2;
						o3=r3;
					} else{
						o2=r3;
						o3=r2;
					}
				}
				else
					if ((r2>r1)&&(r2>r3)){
						o1=r2;
						if (r1>r3){
							o2=r1;
							o3=r3;
						} else{
							o2=r3;
							o3=r1;
						}
					}
					else
						if ((r3>r1)&&(r3>r2)){
							o1=r3;
							if (r1>r2){
								o2=r1;
								o3=r2;
							} else{
								o2=r2;
								o3=r1;
							}
						}
				
				Console.Write(o1+"\t"+o2+"\t"+o3+"\n");
				Console.Write("\n");

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