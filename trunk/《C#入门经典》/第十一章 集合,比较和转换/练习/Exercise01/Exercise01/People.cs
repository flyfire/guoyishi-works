using System;
using System.Collections;

namespace Chapter11
{
    class People : DictionaryBase, ICloneable
    {
        public void Add(Person newPerson)
        {
            Dictionary.Add(newPerson.Name, newPerson);
        }

        public void Remove(string name)
        {
            Dictionary.Remove(name);
        }

        public Person this[string name]
        {
            get
            {
                return (Person)Dictionary[name];
            }
            set
            {
                Dictionary[name] = value;
            }
        }

        public Person[] GetOldest()
        {
            Person oldestPerson = null;
            People oldestPeople = new People();
            Person currentPerson;
            foreach (DictionaryEntry p in Dictionary)
            {
                currentPerson = p.Value as Person;
                if (oldestPerson == null)
                {
                    oldestPerson = currentPerson;
                    oldestPeople.Add(oldestPerson);
                }
                else
                {
                    if (currentPerson > oldestPerson)
                    {
                        oldestPeople.Clear();
                        oldestPeople.Add(currentPerson);
                        oldestPerson = currentPerson;
                    }
                    else
                    {
                        if (currentPerson >= oldestPerson)
                        {
                            oldestPeople.Add(currentPerson);
                        }
                    }
                }
            }
            Person[] oldestPeopleArray = new Person[oldestPeople.Count];
            int copyIndex = 0;
            foreach (DictionaryEntry p in oldestPeople)
            {
                oldestPeopleArray[copyIndex] = p.Value as Person;
                copyIndex++;
            }
            return oldestPeopleArray;
        }
        public object Clone()
        {
            People clonedPeople = new People();
            Person currentPerson, newPerson;
            foreach (DictionaryEntry p in Dictionary)
            {
                currentPerson = p.Value as Person;
                newPerson = new Person();
                newPerson.Name = currentPerson.Name;
                newPerson.Age = currentPerson.Age;
                clonedPeople.Add(newPerson);
            }
            return clonedPeople;
        }
        public IEnumerable Ages
        {
            get
            {
                foreach (object person in Dictionary.Values)
                    yield return (person as Person).Age;
            }
        }
    }
}