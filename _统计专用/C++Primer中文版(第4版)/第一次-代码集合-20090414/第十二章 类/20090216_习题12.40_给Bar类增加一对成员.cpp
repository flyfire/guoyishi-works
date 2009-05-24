class Bar {
public:
	Foo FooVal()
	{
		callsFooVal++;
		return fval;
	}
private:
	static int ival;
	static Foo fval;
	static int callsFooVal;
};

//注意:应在Bar类的定义体外部对其static数据成员进行初始化
int Bar::ival = 20;
Foo Bar::fval(0);
int Bar::callsFooVal = 0;