using System;

namespace Ch11Ex03
{
    public class Program
    {
        static void Main(string[] args)
        {
            Primes PrimesFrom2To10000 = new Primes(2, 10000);
            foreach (long i in PrimesFrom2To10000)
                Console.Write("{0}\t", i);

            Console.ReadKey();
        }
    }
}
