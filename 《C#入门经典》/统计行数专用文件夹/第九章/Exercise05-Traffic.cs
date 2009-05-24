using System;
using Chapter09;

namespace Chapter09
{
    class Traffic
    {
        static void Main(string[] args)
        {
            AddPassenger(new Compact());
            AddPassenger(new SUV());
            AddPassenger(new Pickup());
            AddPassenger(new PassengerTrain());
            System.Console.ReadKey();
        }

        static void AddPassenger(IPassengerCarrier Vehicle)
        {
            Console.WriteLine(Vehicle.ToString());
        }
    }
}