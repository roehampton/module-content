#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char **argv)
{
    int sum = 0;
    int num = -1;
    while (num != 0)
    {
        cout << "Enter a number: ";
        cin >> num;
        sum += num;
    }
    cout << "Total: " << endl;
    return 0;
}