#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    long long num64 = 9000000000000L;
    cout << "long long " << num64 << endl;
    int num32 = int(num64);
    cout << "int " << num32 << endl;
    short num16 = short(num32);
    cout << "short " << num16 << endl;
    char num8 = char(num16);
    cout << "char " << +num8 << endl;
    return 0;
}