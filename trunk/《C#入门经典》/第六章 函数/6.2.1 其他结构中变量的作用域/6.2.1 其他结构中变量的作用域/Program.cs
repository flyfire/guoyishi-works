using System;

namespace Chapter06
{
    class Program
    {
        static void Main()
        {
            int i;
            string text = "";

            for (i = 0; i != 10; ++i)
            {
                text = "Line " + Convert.ToString(i);
                Console.WriteLine("{0}", text);
            }

            Console.WriteLine("Last text output in loop: {0}", text);
            Console.ReadKey();
        }
    }
}