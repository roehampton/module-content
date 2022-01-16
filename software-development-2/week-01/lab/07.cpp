#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	int a = 9;
    cout << "a = " << a << endl;
    int b = 4;
    cout << "b = " << b << endl;
    int c = a + b;
    cout << "a + b = " << c << endl;
    c = a - b;
    cout << "a - b = " << c << endl;
	c = a * b;
    cout << "a * b = " << c << endl;
    c = a / b;
    cout << "a / b = " << c << endl;
	c = a % b;
    cout << "Remainder of a / b = " << c << endl;
	return 0;
}