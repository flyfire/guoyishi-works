typedef string Type;
Type initVal();

class Exercise {
public:
	//typedef double Type;
	Type setVal(Type);
	//Type initVal();
private:
	Type val;
};

Type Exercise::setVal(Type parm) {
	val = parm + initVal();
	return val;
}