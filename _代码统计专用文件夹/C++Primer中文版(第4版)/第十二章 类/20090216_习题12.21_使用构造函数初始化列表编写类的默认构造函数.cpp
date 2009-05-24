ifstream file("text1");
class DemoClass {
public:
	DemoClass(): name("DemoClass"), ival(0), pd(0), inFile(file) {}
private:
	const string name;
	int ival;
	double *pd;
	ifstream &inFile;
}