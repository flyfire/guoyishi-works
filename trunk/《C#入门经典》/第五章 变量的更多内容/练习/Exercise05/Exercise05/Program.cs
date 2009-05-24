//20090419 by Yishi Guo
using System;

namespace Chapter05Exercise
{
    class Program
    {
        static void Main(string[] args)
        {
            string str;
            Console.WriteLine("Enter a string:");
            str = Console.ReadLine();
            string reversedStr = "";
            for (int index = str.Length - 1; index >= 0; index-- )
            {
                reversedStr += str[index];
            }

            Console.WriteLine("Reversed String: {0}", reversedStr);
            Console.ReadKey();
        }
    }
}