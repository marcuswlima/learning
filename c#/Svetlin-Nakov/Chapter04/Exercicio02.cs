using System;

class Program{
        static void Main()
        {
            Titulo("Exercicio02");

			#region //codigo
			//A = πr^2
			//P = 2*π*r
			//Math.PI

			Console.Write("Informe o raio: ");
			double raio = double.Parse(Console.ReadLine());
			
			Console.WriteLine("A área do Circulo é: "+ (Math.PI*Math.Pow(raio,2)));
			Console.WriteLine("O perimetro do circulo é: "+ (2*Math.PI*raio));
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