#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void print_name(string name)
{
    cout << "Hello " << name << endl;
}

string get_name()
{
    string name;
    cout << "Enter your name: ";
    cin >> name;
    return name;
}

int main(int argc, char **argv)
{
    string name = get_name();
    print_name(name);
    return 0;
}