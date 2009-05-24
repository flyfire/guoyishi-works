class Person {
public:
	Person(const std::string &nm, const std::string &addr):
	  name(&nm), address(addr) 
	  { 
	  }
private:
	std::string name;
	std::string address;
};