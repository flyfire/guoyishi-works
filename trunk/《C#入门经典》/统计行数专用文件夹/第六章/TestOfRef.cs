using System;

namespace TestOfRef
{
    class Program
    {
        //test ref
        static void ShowDouble(ref int val)
        {
            val *= 2;
            Console.WriteLine("val doubled = {0}", val);
        }

        //test out
        static int MaxValue(int[] intArray, out int maxIndex)
        {
            int maxVal = intArray[0];
            maxIndex = 0;
            for (int i = 1; i < intArray.Length; ++i)
            {
                if (intArray[i] > maxVal)
                {
                    maxVal = intArray[i];
                    maxIndex = i;
                }
            }
            return maxVal;
        }
        static void Main()
        {
            //test ref
            int myNumber = 12;
            Console.WriteLine("myNumber = {0}", myNumber);
            ShowDouble(ref myNumber);
            Console.WriteLine("myNumber = {0}", myNumber);

            //test out
            int[] myArray = { 1, 2, 3, 9, 3, 2, 0, 2, 4, 7 };
            int maxIndex;
            Console.WriteLine("The maximum value in myArray is {0}",
                MaxValue(myArray, out maxIndex));
            Console.WriteLine("The first occurrence of this value is at element {0}",
                maxIndex + 1);
            Console.ReadKey();
        }
    }
}
