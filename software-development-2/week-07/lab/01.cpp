#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl; using std::string;
int main(int argc, char **argv) { string V001; string V002; string V003;
cout << "Please enter your first name: "; cin >> V001;
if (V001 == "Kevin") { cout << "Hey! Another Kevin\n"; }
else { cout << "Oh well\n"; } cout << "You entered " << V001.length() << " characters" << endl;
cout << "Please enter your last name: "; cin >> V002; cout << "You entered " << V002.length() << " characters" << endl;
V003 = V001 + string(" ") + V002; cout << "Your full name is " << V003 << " which is " << V003.length() << " characters long" << endl; return 0; }