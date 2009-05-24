//COPY!
namespace Myapp {
	void processTrans()
	{
		Bookstore::Sales_item item1, item2, sum;
		while (std::cin >> item1 >> item2) {
			try {
				sum = item1 + item2;
			}
			catch (const Bookstore::isbn_mismatch &e) {
				std::cerr << e.what() << ": left isbn(" << e.left
					<< ") right isbn(" << e.right << ")"
					<< std::endl;
			}
		}
	}
}
