using System;

namespace Ch06Ex02
{
    class Program
    {
        static int MaxValue(int[] intArray)
        {
            int maxVal = intArray[0];
            for (int i = 1; i < intArray.Length; ++i)
            {
                if (intArray[i] > maxVal)
                    maxVal = intArray[i];
            }
            return maxVal;
        }

        static void Main(string[] args)
        {
            int[] myArray = {1, 8, 3, 2, 32, 234, 11, 9, 1};
            int maxVal = MaxValue(myArray);
            Console.WriteLine("The maximum value in myArray is {0}", maxVal);
            Console.ReadKey();
        }
    }
}