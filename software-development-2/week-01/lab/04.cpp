#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of long double: " << sizeof(long double) << " bytes" << endl;
    return 0;
}