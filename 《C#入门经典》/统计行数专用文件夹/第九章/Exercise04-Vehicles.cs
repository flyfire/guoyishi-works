using System;

namespace Chapter09
{
    public interface IPassengerCarrier
    {
    }

    public interface IHeavyLoadCarrier
    {
    }

    public abstract class Vehicle
    {
    }

    public abstract class Car : Vehicle
    {
    }

    public abstract class Train
    {
    }

    public class Compact : Car, IPassengerCarrier
    {
    }

    public class SUV : Car, IPassengerCarrier
    {
    }

    public class Pickup : Car, IPassengerCarrier, IHeavyLoadCarrier
    {
    }

    public class PassengerTrain : Train, IPassengerCarrier
    {
    }

    public class FreightTrain : Train, IHeavyLoadCarrier
    {
    }

    public class T424DoubleBogey : Train
    {
    }
}
