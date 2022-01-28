#include <iostream>

using std::cout;
using std::endl;
using std::boolalpha;
using std::noboolalpha;

int main(int argc, char **argv)
{
    int a = -500;
    unsigned int b = -500;
    unsigned int c = (unsigned int)a;
    float f = -500;

    // Print out values as signed and unsigned
    cout << "a signed: " << a << " a unsigned: " << (unsigned int)a << endl;
    cout << "b signed: " << (int)b << " b unsigned: " << b << endl;
    cout << "c signed: " << (int)c << " c unsigned: " << c << endl;

    // Print out if values are equal
    cout << boolalpha << "a == b: " << (a == b) << noboolalpha << endl;
    cout << boolalpha << "a == c: " << (a == c) << noboolalpha << endl;
    cout << boolalpha << "a == f: " << (a == f) << noboolalpha << endl;
    
    return 0;
}