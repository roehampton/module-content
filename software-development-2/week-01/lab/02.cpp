#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello " << name << endl;
    return 0;
}