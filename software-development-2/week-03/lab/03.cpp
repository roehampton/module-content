#include <iostream>
#include <limits>

using std::cout;
using std::endl;
using std::numeric_limits;

int main(int argc, char **argv)
{
    cout << "unsigned int is " << sizeof(unsigned int);
    cout << " bytes, min value " << numeric_limits<unsigned int>::min();
    cout << " max value " << numeric_limits<unsigned int>::max() << endl;
    cout << "int is " << sizeof(int);
    cout << " bytes, min value " << numeric_limits<int>::min();
    cout << " max value " << numeric_limits<int>::max() << endl;
    return 0;
}