using System;

namespace Ch11Ex01
{
    public class Chicken : Animal
    {
        public void LayEgg()
        {
            Console.WriteLine("{0} has laid an egg.", name);
        }

        public Chicken(String newName)
            : base(newName)
        {
        }
    }
}