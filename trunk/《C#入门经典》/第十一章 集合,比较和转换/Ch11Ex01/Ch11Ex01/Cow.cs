using System;

namespace Ch11Ex01
{
    public class Cow : Animal
    {
        public void Milk()
        {
            Console.WriteLine("{0} has been milked.", name);
        }

        public Cow(string newName)
            : base(newName)
        {
        }

        public void MilkCow(Animal myAnimal)
        {
            Cow myCow = myAnimal as Cow;
            if (myCow != null)
            {
                myCow.Milk();
            }

            else
            {
                Console.WriteLine("{0} isn't a cow, and so can't be milked.",
                    myAnimal.Name);
            }
        }
    }
}