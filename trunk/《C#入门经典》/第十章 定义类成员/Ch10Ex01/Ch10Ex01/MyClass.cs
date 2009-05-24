using System;

namespace Ch10Ex01
{
    public class MyClass
    {
        public readonly string Name;
        private int intVal;

        public int Val
        {
            get
            {
                return intVal;
            }

            set
            {
                if (value >= 0 && value <= 10)
                    intVal = value;
                else
                    throw (new ArgumentOutOfRangeException("Val", value,
                        "Val must be assinged a value between 0 and 10."));
            }
        }
        public override string ToString()
        {
            return "Name: " + Name + "\nVal: " + Val;
        }

        private MyClass()
            : this("Default Name")
        {
        }

        public MyClass(string newName)
        {
            Name = newName;
            intVal = 0;
        }
    }
}