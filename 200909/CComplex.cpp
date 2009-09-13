#include <iostream.h>

///////////////////////////////
// Create by Yishi Guo
// Date: 20090907
// At: 804 Room Yifu Building
///////////////////////////////

class CComplex {
	private:
		double real, image;

	public:
		// Default constructor
		CComplex() {
			this->real = 0.0;
			this->image = 0.0;
		}

		// Constructor
		CComplex(double real, double image) {
			this->real = real;
			this->image = image;
		}

		// Display the results of the Complex' values
		void Display() {
			cout << this->real << "+" << this->image << "i\n";
		}
};

int main() {
	double real = 0.0, image = 0.0;  // Create properties

	// Get the first CComplex value
	cout << "Enter the value of c1: ";
	cin >> real >> image;
	CComplex c1(real, image);
	c1.Display();

	// Get the second CComplex value
	cout << "Enter the value of c2: ";
	cin >> real >> image;
	CComplex c2(real, image);
	c2.Display();

	// Copy the first value to the second
	cout << "\nCopy the value of c1 to c2:\r\n";
	c2 = c1;
	c2.Display();

	return 0;
}