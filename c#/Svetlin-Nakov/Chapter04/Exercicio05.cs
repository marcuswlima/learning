using System;

class Program{
        static void Main()
        {
            Titulo("Exercicio05");

			#region //codigo
			int n1=1, n2=100;
			
			for (int i=n1; i<=n2; i++){
				if (Resto(i,49)==0)
					Console.Write(i+" ") ;
			}
			Console.WriteLine("");
			#endregion

			Console.WriteLine("");
			Console.WriteLine("************************************");
        }


		#region //utils
        static int Resto(int divisor, int dividendo)
        {
            return divisor % dividendo;
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
		#endregion

}