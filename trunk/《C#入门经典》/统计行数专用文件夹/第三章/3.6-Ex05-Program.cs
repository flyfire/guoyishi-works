using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int intA, intB, intC, intD;
            Console.WriteLine("Enter an integer:");
            intA = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter 2nd integer:");
            intB = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter 3th integer:");
            intC = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter 4th integer:");
            intD = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("{0} * {1} * {2} * {3} = {4}", intA, intB, intC, intD, intA * intB * intC * intD);
            Console.ReadKey();
        }
    }
}
