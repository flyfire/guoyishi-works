using System;
using System.Collections.Generic;
using System.Text;

namespace Ch04Ex01
{
    class Ch04Ex01
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter an integer:");
            int myInt = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Integer less than 10? {0}", myInt < 10);
            Console.WriteLine("Integer between 0 and 5? {0}", (0 <= myInt) && (myInt <= 5));
            Console.WriteLine("Bitwise AND of Integer and 10 = {0}", myInt & 10);
            Console.ReadKey();
        }
    }
}