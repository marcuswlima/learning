using Svetlin_Nakov;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Hello, World!");
        Cat someCat = new();
        someCat.SayMiau();
        Console.WriteLine("The color of cat {0} is {1}.",someCat.Name, someCat.Color);

        Cat someCat2 = new("Johnny", "brown");
        someCat2.SayMiau();
        Console.WriteLine("The color of cat {0} is {1}.",
        someCat2.Name, someCat.Color);
    }
}
