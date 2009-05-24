using System;

namespace Chapter10
{
    class myCopyableClass
    {
        private int myInt;

        public int ContainedInt
        {
            get
            {
                return myInt;
            }
            set
            {
                myInt = value;
            }
        }

        public myCopyableClass GetCopy()
        {
            return (myCopyableClass)MemberwiseClone();
        }

        public static void Main(string[] args)
        {
            myCopyableClass obj1 = new myCopyableClass();
            obj1.ContainedInt = 12;
            myCopyableClass obj2 = obj1.GetCopy();
            obj2.ContainedInt = 21;
            Console.WriteLine("obj1 = " + obj1.ToString() + " obj2 = " + obj2.ToString());
            Console.WriteLine("int1 = " + obj1.ContainedInt + " int2 = " + obj2.ContainedInt);
            Console.ReadKey();
        }
    }
}