using System;
using System.Diagnostics;

namespace Ch07Ex01
{
    class Program
    {
        static void Main()
        {
            int[] testArray = { 4, 7, 3, 3, 4, 2, 0, 8, 0, 2, 8, 9, 2, 4, 5, 12, 2 };
            int[] maxValIndices;
            int maxVal = Maxima(testArray, out maxValIndices);
            Console.WriteLine("Maximum value {0} found at element indices:",
                maxVal);
            foreach (int index in maxValIndices)
            {
                Console.WriteLine(index);
            }

            Console.ReadKey();
        }

        static int Maxima(int[] integers, out int[] indices)
        {
            Debug.WriteLine("Maximum  value search started.");
            indices = new int[1];
            int maxVal = integers[0];
            indices[0] = 0;
            int count = 1;
            Debug.WriteLine(string.Format("Maximum  value initialized to {0}, at element index 0.", maxVal));
            for (int i = 1; i < integers.Length; ++i)
            {
                Debug.WriteLine(string.Format(
                    "Now looking at element at index {0}.", i));
                if (integers[i] > maxVal)
                {
                    maxVal = integers[i];
                    count = 1;
                    indices = new int[1];
                    indices[0] = 1;
                    Debug.WriteLine(string.Format(
                        "New maximum found. New value is {0}, at element index{1}.", maxVal, i));
                }
                else
                {
                    if (integers[i] == maxVal)
                    {
                        count++;
                        int[] oldIndices = indices;
                        indices = new int[count];
                        oldIndices = new int[count];
                        oldIndices.CopyTo(indices, 0);
                        indices[count - 1] = i;
                        Debug.WriteLine(string.Format(
                            "Duplicate maximum found at element index {0}.", indices));
                    }
                }
            }
            Trace.WriteLine(string.Format(
                "Maximum value {0} found, with {1}  occurrences.", maxVal, count));
            Debug.WriteLine("Maximum value search completed.");
            return maxVal;
        }
    }
}