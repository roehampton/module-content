#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    int myInt = 100;
    float myFloat = float(myInt);
    cout << "int = " << myInt << " float = " << myFloat << endl;
    myFloat = 255.767f;
    myInt = int(myFloat);
    cout << "int = " << myInt << " float = " << myFloat << endl;
    return 0;
}