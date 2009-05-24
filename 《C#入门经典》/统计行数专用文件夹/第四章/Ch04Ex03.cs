using System;

namespace Ch04Ex03
{
    class Program
    {
        static void Main(string[] args)
        {
            const string myName = "karli";
            const string sexyName = "angelina";
            const string sillyName = "ploppy";
            string name;
            Console.WriteLine("What is your name?");
            name = Console.ReadLine();
            switch (name.ToLower())
            {
                case myName:
                    Console.WriteLine("You have the same name as me!");
                    break;
                case sexyName:
                    Console.WriteLine("My, what a sexy name have!");
                     break;    //break is not RETURN;
                case sillyName:
                    Console.WriteLine("That's a very silly name.");
                    break;
                default:
                    Console.WriteLine("Are you {0} ?!", name);
                    break;
            }
            Console.WriteLine("Hello {0}", name);
            Console.ReadKey();
        }
    }
}