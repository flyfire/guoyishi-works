using System;

namespace Chapter06
{
    class Program
    {
        delegate string ReadLineDelegate();

        static void Main()
        {
            ReadLineDelegate readLine = new ReadLineDelegate(Console.ReadLine);
            Console.WriteLine("Type a string:");
            string userInput = readLine();
            Console.WriteLine("You typed: {0}", userInput);
            Console.ReadKey();
        }
    }
}