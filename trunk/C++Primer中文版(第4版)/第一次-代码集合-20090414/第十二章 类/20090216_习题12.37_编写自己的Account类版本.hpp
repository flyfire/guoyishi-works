class Account {
public:
	Account(string own, double amnt)
	{
		owner = own;
		amount = amnt;
	}

	void applyint()
	{
		amount += amount * inerestRate;
	}

	static double rate()
	{
		return interestRate;
	}

	static void rate(double newRate)
	{
		interRate = newRate;
	}

	double deposit(double amnt)
	{
		amount += amnt;
		return amount;
	}

	bool withdraw(double amnt)
	{
		if (amount < amnt)
			return false;
		else {
			amount -= amnt;
			return true;
		}
	}

	double getBalance()
	{
		return amount;
	}
private:
	string owner;
	double amount;
	static double interestRate;
};

double Account::interestRate = 2.5;