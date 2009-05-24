using System;

namespace Chapter10
{
    class myClass
    {
        private string myString;

        public string ContainedString
        {
            get
            {
                return myString;
            }
            set
            {
                myString = value;
            }
        }

        public virtual string GetString()
        {
            return ContainedString;
        }
    }

    class myDerivedClass : myClass
    {
        public override string GetString()
        {
            return base.GetString() + " (output from derived class)";
        }
    }
}