using System;

class Program{
	
        static void Main()
        {
            Titulo("Capitulo07 - Exercicio01");
			#region //codigo
			int[] numeros;
			int TAM=10;
			numeros = new int[TAM];
			
			for (int i=0;i<=numeros.Length-1;i++){
				numeros[i]=i*5;
			}
			
			PrintIntVector(arrei:numeros,titulo:"Exercicio01->");
			#endregion

			Console.WriteLine("");
			Console.WriteLine("************************************");
        }
		
		#region //ImprimirArrays
		static void PrintStrMatriz(string[,] matriz,string titulo="Matrix"){
			int MaiorLength=0;
			//descobrir o maior tamanho de elemento
			for (int row = 0; row < matriz.GetLength(0); row++){
				for (int col = 0; col < matriz.GetLength(1); col++){
					if (matriz[row,col].Length > MaiorLength)
						MaiorLength = matriz[row,col].Length;
				}
			}

			Console.Write("\n"+titulo+": \n");
			
			for (int row = 0; row < matriz.GetLength(0); row++){
				for (int col = 0; col < matriz.GetLength(1); col++){
					Console.Write("[{0},{1}]={2} ",row,col,matriz[row,col].PadRight(MaiorLength,' '));
				}
				Console.Write("\n");
			}

			Console.Write("\n");
		}

		static void PrintIntMatriz(int[,] matriz,string titulo="Matrix"){
			int mariorElemento=0, maiorLength=0;
			//descobrir o maior elemento
			for (int row = 0; row < matriz.GetLength(0); row++){
				for (int col = 0; col < matriz.GetLength(1); col++){
					if (matriz[row,col] > mariorElemento)
						mariorElemento = matriz[row,col];
				}
			}
			
			maiorLength = mariorElemento.ToString().Length;

			Console.Write("\n"+titulo+": \n");
			
			for (int row = 0; row < matriz.GetLength(0); row++){
				for (int col = 0; col < matriz.GetLength(1); col++){
					Console.Write("[{0},{1}]={2} ",row,col,matriz[row,col].ToString().PadRight(maiorLength,' ')
					              );
				}
				Console.Write("\n");
			}

			Console.Write("\n");
		}

		static void PrintStrVector(string[] arrei,string titulo="Vector"){
			Console.Write("\n"+titulo+": ");

			for (int i=0;i<=arrei.Length-1;i++)
				Console.Write("[{0}]={1} ",i,arrei[i]);
			
			Console.Write("\n");
		
		}

		static void PrintIntVector(int[] arrei,string titulo="Vector"){
			Console.Write("\n"+titulo+": ");

			for (int i=0;i<=arrei.Length-1;i++)
				Console.Write("[{0}]={1} ",i,arrei[i]);

			Console.Write("\n");
		}

		#endregion
		
		#region //NumeralSystem
		static int HexadecinalToDecimal(string hexadecimal)
		{
			int resposta=0,numero;
			char[] letras = new char[hexadecimal.Length];  

			//reverter o indice
			for (int i=0;i<=(hexadecimal.Length-1); i++){
				letras[hexadecimal.Length-1-i]=hexadecimal[i];
			}

			for (int i=0;i<=(letras.Length-1); i++){
				numero=0;
				switch(letras[i]){
					case 'A':numero=10;break;
					case 'B':numero=11;break;
					case 'C':numero=12;break;
					case 'D':numero=13;break;
					case 'E':numero=14;break;
					case 'F':numero=15;break;
					default:numero = Int32.Parse(letras[i].ToString()); break;		
				}
				resposta += numero*(int)Math.Pow(16,i); 

			}
			return resposta;
		}

		static long BinaryToDecimal(string binario){
			long[] restos = new long[20];  
			int @base=10,qtdElements=0;
			long numero=Int64.Parse(binario), resposta;
			for(int i=0; numero>0; i++){
				restos[i]=Remainder(numero,@base);
				numero /= @base;    
				qtdElements++;
			}
			
			resposta=0;
			for (int i=0;i<qtdElements; i++){
				resposta += restos[i]*(long)Math.Pow(2,i); 
			}

			return resposta;
		}

		static string DecimalTo(long numero,int @base){
			int   i;       
			string[] restos = new string[15];  
			string resposta="";

			for(i=0; numero>0; i++)      
			{      
				restos[i]=Remainder(numero,@base).ToString();
				if (@base==16){
					switch (restos[i]){
						case "10":restos[i]="A";break;
						case "11":restos[i]="B";break;
						case "12":restos[i]="C";break;
						case "13":restos[i]="D";break;
						case "14":restos[i]="E";break;
						case "15":restos[i]="F";break;
						case "16":restos[i]="0";break;
					}
				}
				numero /= @base;    
			}      

			for(i=i-1 ;i>=0 ;i--)      
				resposta += restos[i];
			
			return resposta;
		}

		static string DecimalToHexadecimal(int numero){
			return DecimalTo(numero,16);
		}

		static string DecimalToBinary(int numero){
			return DecimalTo(numero,2);
		}
		#endregion
		
		#region //Math
		static long Fatorial(long numero){
			long produto=1;
			for (long i=1;i<=numero;i++){
				produto *= i;
			}
			return produto;
		}
		
		static double Catalan(long numero){
			return Fatorial(2*numero)/(Fatorial(numero+1)*Fatorial(numero));
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
		static long Remainder(long divisor, int dividendo)
        {
            return divisor % dividendo;
        }
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