#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
    char charValue;
    short shortValue;
    int intValue;
    float floatValue;
    string stringValue;

    cout << "Enter a char: ";
    cin >> charValue;
    cout << "You entered: " << charValue << endl;
    cout << "Enter a short: ";
    cin >> shortValue;
    cout << "You entered: " << shortValue << endl;
    cout << "Enter an int: ";
    cin >> intValue;
    cout << "You entered: " << intValue << endl;
    cout << "Enter a float: ";
    cin >> floatValue;
    cout << "You entered: " << floatValue << endl;
    cout << "Enter a string: ";
    cin >> stringValue;
    cout << "You entered: " << stringValue << endl;

    return 0;
}