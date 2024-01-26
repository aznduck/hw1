#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_back("eight");
  // dat.push_front("seven");
  // dat.push_back("nine");
  dat.pop_back();
  dat.push_front("seven");
  dat.pop_front();
  dat.push_back("eight");
  cout << dat.get(0) << endl;
  // prints: 8 7 9
  cout << dat.size() << endl;  // prints 3 since there are 3 strings stored
}
