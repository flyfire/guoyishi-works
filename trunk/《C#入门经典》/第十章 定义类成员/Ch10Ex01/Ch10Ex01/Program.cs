﻿using System;

namespace Ch10Ex01
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Creating object myObj...");
            MyClass myObj = new MyClass("My Object");
            Console.WriteLine("myObj created.");

            for (int i = -1; i <= 0; i++)
            {
                try
                {
                    Console.WriteLine("\nAttempting to assign {0} to myObj.val...", i);
                    myObj.Val = i;
                    Console.WriteLine("Value {0} assigned to myObj.val.", myObj.Val);
                }
                catch (Exception e)
                {
                    Console.WriteLine("Exception {0} thrown.", e.GetType().FullName);
                    Console.WriteLine("Message:\n\"{0}\"", e.Message);
                }
            }
            Console.WriteLine("\nOutputing myObj.ToString()...");
            Console.WriteLine(myObj.ToString());
            Console.WriteLine("myObj.ToString() Output.");
            Console.ReadKey();
        }
    }
}