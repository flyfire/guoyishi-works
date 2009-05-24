using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            double resultVar;
            double var1, var2, var3, var4, var5;
            resultVar = 0.0;
            var1 = 1.0;
            var2 = 2.0;
            var3 = 3.0;
            var4 = 40.0;
            var5 = 5.0;
            resultVar += var1 * var2 + var3 % var4 / var5;
            Console.WriteLine("resultVar = " + resultVar);
            Console.WriteLine((var1 * var2) + ((var3 % var4) / var5));   //正确结果.
            Console.WriteLine((var1 * var2) + (var3 % (var4 / var5)));
            Console.ReadKey();
        }
    }
}
