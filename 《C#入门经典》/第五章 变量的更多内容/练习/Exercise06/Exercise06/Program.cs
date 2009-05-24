using System;

namespace Chapter05Exercise
{
    class Program
    {
        static void Main(string[] args)
        {
            string myString;
            Console.WriteLine("Enter a string:");
            myString = Console.ReadLine();
            myString = myString.Replace("no", "yes");
            Console.WriteLine("Replace \"yes\" from \"no\": {0}", myString);

            Console.ReadKey();
        }
    }
}