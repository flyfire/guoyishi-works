using System;

namespace Ch06Ex05
{
    class Program
    {
        delegate double ProcessDelegate(double Param1, double Param2);

        static double Multiply(double param1, double param2)
        {
            return param1 * param2;
        }

        static double Divide(double param3, double param4)
        {
            return param3 / param4;
        }

        static void Main()
        {
            ProcessDelegate process;
            Console.WriteLine("Enter 2 numbers separated with a comma:");
            string input = Console.ReadLine();
            int commaPos = input.IndexOf(',');
            double param1 = Convert.ToDouble(input.Substring(0, commaPos));
            double param2 = Convert.ToDouble(input.Substring(commaPos + 1, input.Length - commaPos - 1));
            Console.WriteLine("Enter M to multiply or D to divide:");
            input = Console.ReadLine();
            if (input[0] == 'M' || input[0] == 'm')
                process = new ProcessDelegate(Multiply);
            else
                process = new ProcessDelegate(Divide);

            Console.WriteLine("Result: {0}", process(param1, param2));
            Console.ReadKey();
        }
    }
}