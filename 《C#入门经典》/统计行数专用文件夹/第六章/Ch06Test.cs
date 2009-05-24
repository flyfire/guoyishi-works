using System;

namespace Chapter06
{
    class Program
    {
        struct customerName
        {
            public string firstName, lastName;

            public string getName()
            {
                return firstName + " " + lastName;
            }
        }

        static void Main()
        {
            customerName myCustomer;
            myCustomer.firstName = "John";
            myCustomer.lastName = "Franklin";
            Console.WriteLine(myCustomer.getName());

            Console.ReadKey();
        }
    }
}