class ifThenElse {
public:
	int operator() (int val1, int val2. int val3)
	{
		return val1 ? val2 : val3;
	}
};

//OR
template<typename T>
class ifThenElse {
	T operator() (T val1, T val2, T val3)
	{
		return val1 ? val2 : val3;
	}
};