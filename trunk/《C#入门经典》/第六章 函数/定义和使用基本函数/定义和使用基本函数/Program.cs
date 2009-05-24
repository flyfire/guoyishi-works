using System;

namespace Chapter06
{
    class Program
    {
        static string myString;

        static void Write()
        {
            string myString = "String defined in Write()";
            Console.WriteLine("Now in Write()");
            Console.WriteLine("Local myString = {0}", myString);
            Console.WriteLine("Global myString = {0}", Program.myString);
        }

        static void Main()
        {
            string myString = "String defined in Main()";
            Program.myString = "Global string";
            Write();
            Console.WriteLine("\nNow in Main()");
            Console.WriteLine("Local myString = {0}", myString);
            Console.WriteLine("Global myString = {0}", Program.myString);
            Console.ReadKey();
        }
    }
}