#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    unsigned int unum = 4000000000;
    int num = int(unum);
    cout << "unsigned " << unum << " signed " << num << endl;
    return 0;
}