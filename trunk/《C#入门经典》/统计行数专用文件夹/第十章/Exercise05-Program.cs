using System;
using Ch10CardLib;

namespace Chapter10
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Deck playDeck = new Deck();
                playDeck.Shuffle();
                bool isFlush = false;
                int flushHandIndex = 0;
                for (int hand = 0; hand < 10; hand++)
                {
                    isFlush = true;
                    Suit flushSuit = playDeck.GetCard(hand * 5).suit;
                    for (int card = 1; card < 5; card++)
                    {
                        if (playDeck.GetCard(hand * 5 + card).suit != flushSuit)
                        {
                            isFlush = false;
                        }
                        if (isFlush)
                        {
                            flushHandIndex = hand * 5;
                        }
                    }
                    if (isFlush)
                    {
                        Console.WriteLine("Flush!");
                        for (int card = 0; card < 5; card++)
                        {
                            Console.WriteLine(playDeck.GetCard(flushHandIndex + card));
                        }
                    }
                    else
                    {
                        Console.WriteLine("No flush.");
                    }
                    Console.ReadKey();
                }
            }
        }
    }
}
