using System;

namespace Exercise
{
    class Program
    {
        static void Main()
        {
            int[] intArray = new int[10];
            for (int index = 0; index != 10000; index++)
            {
                Console.WriteLine("index == " + index);
                if (index >= 5000)
                {
                    Console.WriteLine("index >= 5000");
                    Console.WriteLine("index == " + index);
                    intArray[100] = index;
                }
            }
        }
    }
}