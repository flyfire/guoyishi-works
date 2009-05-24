using System;

namespace Chapter06
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = args[0];
            int number = Convert.ToInt32(args[1]);
            Console.WriteLine("The string: " + str);
            Console.WriteLine("The Integer: " + number);
            Console.ReadKey();
        }
    }
}