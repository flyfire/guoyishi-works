using System;

namespace Ch06Ex03
{
    class Program
    {
        static int SumVal(params int[] vals)
        {
            int sum = 0;
            foreach (int val in vals)
            {
                sum += val;
            }

            return sum;
        }

        static void Main()
        {
            int sum = SumVal(1, 2, 3, 4, 5);
            Console.WriteLine("Summed Values = {0}", sum);
            Console.ReadKey();
        }
    }
}