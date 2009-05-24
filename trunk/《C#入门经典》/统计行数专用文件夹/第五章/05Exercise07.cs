//20090419 by Yishi Guo
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
            myString = "\"" + myString.Replace(" ", "\" \"") + "\"";
            Console.WriteLine("Added double quotes arround words: {0}", myString);
            Console.ReadLine();
        }
    }
}