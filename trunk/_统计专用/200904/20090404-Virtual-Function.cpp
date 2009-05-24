#include <iostream>
#include <vector>
using namespace std;

class Animal
{
public:
	virtual void eat() const { cout << "I eat like a generic Animal." << endl; }

	virtual ~Animal() {}
};

class Wolf : public Animal
{
public:
	void eat() const { cout << "I eat like a wolf!" << endl; }
};

class Fish : public Animal
{
public:
	virtual void eat() const { cout << "I eat like a fish!" << endl; }
};

class GoldFish : public Fish
{
public:
	void eat() const { cout << "I eat like a goldfish!" << endl; }
};

class OtherAnimal : public Animal
{
};

int main()
{
	vector<Animal*> animals;
	animals.push_back(new Animal());
	animals.push_back(new Wolf());
	animals.push_back(new Fish());
	animals.push_back(new GoldFish());
	animals.push_back(new OtherAnimal());

	for (vector<Animal*>::const_iterator iter = animals.begin();
	iter != animals.end(); ++iter) {
		(*iter)->eat();
	}

	return 0;
}