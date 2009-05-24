using System;

namespace Ch06Ex04
{
    class Program
    {
        static int Main(String[] args)
        {
            Console.WriteLine("{0} command line arguments were secified:", args.Length);
            foreach (String arg in args)
                Console.WriteLine(arg);

            Console.ReadKey();

            return 0;
        }
    }
}