using System;

class Program{
	
        static void Main()
        {
            Titulo("Exercicio 06 e 07");
			#region //codigo
			
			int N,K;
			double resultado;
			Console.Write("Vez\tN\tK\tvez!\tN!\tK!\tExe06\t\tExe07\n");

			for (int vez=1; vez<=10; vez++){
				Console.Write(vez+"\t");
				
				N = IntRandom(1,10);
				K = IntRandom(1,10);

				Console.Write(N+"\t");
				Console.Write(K+"\t");
				Console.Write(fatorial(vez)+"\t");
				Console.Write(fatorial(N)+"\t");
				Console.Write(fatorial(K)+"\t");
				
				if (K<N){
					resultado = (double)fatorial(N)/fatorial(K);
					Console.Write(resultado+"\t\t");
					resultado = ((double)fatorial(N)*fatorial(K))/fatorial(N-K);
					//resultado = (double)N/K;
					Console.Write(resultado+"\t");
				}
				else
					Console.Write("Impossível"+"\t");


				Console.Write("\n");
			}
			#endregion

			Console.WriteLine("");
			Console.WriteLine("************************************");
        }
		
		#region //Math
		
		static int fatorial(int numero){
			int produto=1;
			for (int i=1;i<=numero;i++){
				produto *= i;
			}
			return produto;
		}


		static int Discriminant(int a, int b, int c){
			return (b*b) - (4*a*c);
		}
		static void RealRoots(int a, int b, int c, out string mensagem){
			int d=Discriminant(a,  b, c);
			mensagem=" ";
			
			if (d<0)
				mensagem=d+"\t"+"no real roots";
			else if (d==0)
				mensagem=(d+"\t"+(-1)*b/(a*2))+"\t";
			else if (d>0)
				mensagem=(d+"\t"+
						 (((-1)*b)+(Math.Sqrt(d)) / (2*a)) + "\t" 
					   + (((-1)*b)-(Math.Sqrt(d)) / (2*a)) + "\t"
						 );
		}
		#endregion
		
		#region //numeroExtenso
		static string NumeroExtensoUnidade(int numero){
			string resposta;
			switch (numero)
			{
				case 0:resposta="zero"	;break;
				case 1:resposta="one"	;break;
				case 2:resposta="two"	;break;
				case 3:resposta="three"	;break;
				case 4:resposta="four"	;break;
				case 5:resposta="five"	;break;
				case 6:resposta="six"	;break;
				case 7:resposta="seven"	;break;
				case 8:resposta="eight"	;break;
				case 9:resposta="nine"	;break;
				default:resposta="Unknown"; break;			
			}
			return resposta;
		}
		

		static string NumberEnglishPronuciation(int numero){
			int unidade,dezena,centena;
			string resposta;

			unidade = Remainder(numero,10);
			numero = numero/10;
			dezena = Remainder(numero,10);
			numero = numero/10;
			centena = Remainder(numero,10);

			resposta = "";
			//Centena
			if (centena>0)
				resposta = NumeroExtensoUnidade(centena)+" hundread ";

			//Dezena e Unidade
			if (dezena==1){
				switch((dezena*10)+unidade){
					case 10:resposta += "ten";      break;
					case 11:resposta += "eleven";   break;
					case 12:resposta += "twelve";   break;
					case 13:resposta += "thirteen"; break;
					case 14:resposta += "fourteen"; break;
					case 15:resposta += "fivteen";  break;
					case 16:resposta += "sixteen";  break;
					case 17:resposta += "seventeen";break;
					case 18:resposta += "eithteen"; break;
					case 19:resposta += "nineteen"; break;
				}
			}else{
				switch(dezena){
					case 2:resposta += "twenty "; break;
					case 3:resposta += "thirty "; break;
					case 4:resposta += "forty ";  break;
					case 5:resposta += "fifty ";  break;
					case 6:resposta += "sixth ";  break;
					case 7:resposta += "seventy ";break;
					case 8:resposta += "eitghty ";break;
					case 9:resposta += "ninety "; break;
				}

				if (unidade > 0) 
					resposta += NumeroExtensoUnidade(unidade);

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