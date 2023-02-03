using System;

class Program{
        static void Main()
        {
            Titulo("Chapter 4. Console Input and Output");
            Console.Write("Numero1: ");
			int v1 = Int32.Parse(Console.ReadLine());
            Console.Write("Numero2: ");
			int v2 = Int32.Parse(Console.ReadLine());
            Console.Write("Numero3: ");
			int v3 = Int32.Parse(Console.ReadLine());

            Console.WriteLine("A soma dos numeros é " + (v1+v2+v3));
        }


		#region
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