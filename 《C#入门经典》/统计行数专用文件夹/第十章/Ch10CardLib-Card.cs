using System;
using System.Collections.Generic;
using System.Text;

namespace Ch10CardLib
{
    public class Card
    {
        public readonly Suit suit;
        public readonly Rank rank;

        public Card(Suit newsuit, Rank newrank)
        {
            suit = newsuit;
            rank = newrank;
        }

        private Card()
        {
        }

        public override string ToString()
        {
            return "The " + rank + " of " + suit + "s";
        }
    }
}
