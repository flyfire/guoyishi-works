using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int myInteger;
            string myString;
            myInteger = 17;
            myString = "\"myInteger\" is";
            Console.WriteLine("{0} {1}.", myString, myInteger); 
            Console.WriteLine(@"C:\Temp\MyDir\MyFile.doc"); //使用@,逐字指定的字符串字符值
            Console.ReadKey();
        }
    }
}
