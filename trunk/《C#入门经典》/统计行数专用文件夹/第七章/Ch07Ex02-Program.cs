using System;
using System.Collections;
using System.Diagnostics;

namespace Ch07Ex02
{
    class Program
    {
        static string[] eTypes = { "none", "simple", "index", "nested index" };

        static void Main(string[] args)
        {
            foreach (string eType in eTypes)
            {
                try
                {
                    Console.WriteLine("Main() try block reached.");
                    Console.WriteLine("ThrowException(\"{0}\") called.", eType);
                    ThrowException(eType);
                    Console.WriteLine("Main() try block continues.");
                }
                catch (System.IndexOutOfRangeException e)
                {
                    Console.WriteLine("Main() general catch block reached.");
                }
                finally
                {
                    Console.WriteLine("Main() finally block reached.");
                }
                Console.WriteLine();
            }
            Console.ReadKey();
        }

        static void ThrowException(string exceptionType)
        {
            Console.WriteLine("ThrowException(\"{0}\") reached.", exceptionType);
            switch (exceptionType)
            {
                case "none":
                    Console.WriteLine("Not throwing an exception.");
                    break;
                case "simple":
                    Console.WriteLine("Throwing System.Exception.");
                    throw (new System.Exception());
                    break;
                case "index":
                    Console.WriteLine("Throwing System.INdexOutOfRangeException.");
                    eTypes[4] = "error";
                    break;
                case "nested index":
                    try
                    {
                        Console.WriteLine("ThrowException(\"nested index\") " +
                            "try block reached.");
                        Console.WriteLine("ThrowException(\"index\") called.");
                        ThrowException("index");
                    }
                    catch
                    {
                        Console.WriteLine("ThrowException(\"nested index\") general" +
                            " catch block reached.");
                    }
                    finally
                    {
                        Console.WriteLine("ThrowException(\"nested index\") finally"
                            + " block reached.");
                    }
                    break;
            }
        }
    }
}