using System;

namespace Chapter
{
    class Program
    {
        enum orientation : byte
        {
            north = 1,
            south = 2,
            east = 3,
            west = 4
        }

        static void Main()
        {
            orientation myDirection;
            for (byte myByte = 1; myByte < 10; myByte++)
            {
                try
                {
                    Console.WriteLine("myByte: {0}", myByte);
                    myDirection = checked((orientation)myByte);
                    if ((myDirection < orientation.north) ||
                        (myDirection > orientation.west))
                    {
                        throw new ArgumentOutOfRangeException("myByte", myByte,
                        "Value must be between 1 and 4");
                    }
                }
                catch (ArgumentOutOfRangeException e)
                {
                    Console.WriteLine(e.Message);
                    Console.WriteLine("Assigning default value, orientation.north.");
                    myDirection = orientation.north;
                }

                Console.WriteLine("myDirection = {0}", myDirection);
            }

            Console.ReadKey();
        }
    }
}