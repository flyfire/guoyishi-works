#include <iostream>
#include "g_parser.h"
using namespace std;

int main()
{
  char expstr[80];

  // Demonstrate floating-point parser.
  parser<double> ob;

  cout << "Floating-point parser.  ";
  cout << "Enter a period to stop\n";
  for(;;) {
    cout << "Enter expression: ";
    cin.getline(expstr, 79);
    if(*expstr=='.') break;
    cout << "Answer is: " << ob.eval_exp(expstr) << "\n\n";
  }
  cout << endl;

  // Demonstrate integer-based parser.
  parser<int> Iob;

  cout << "Integer parser.  ";
  cout << "Enter a period to stop\n";
  for(;;) {
    cout << "Enter expression: ";
    cin.getline(expstr, 79);
    if(*expstr=='.') break;
    cout << "Answer is: " << Iob.eval_exp(expstr) << "\n\n";
  }

  return 0; 
}
