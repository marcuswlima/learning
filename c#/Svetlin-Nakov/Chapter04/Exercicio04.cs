using System;

class Program{
        static void Main()
        {
            Titulo("Exercicio04");

			#region //codigo
			int hexNum = 2013; 
			Console.WriteLine("|0x{0,-8:X}|", hexNum); 
			double fractNum = -1.856; 
			Console.WriteLine("|{0,-10:f2}|", fractNum);
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
		#endregion

}