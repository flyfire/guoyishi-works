using System;
using Ch09ClassLib;

namespace Ch09Ex02
{
    class Program
    {
        static void Main()
        {
            MyExternalClass myObj = new MyExternalClass();
            Console.WriteLine(myObj.ToString());
            Console.ReadKey();
        }
    }
}