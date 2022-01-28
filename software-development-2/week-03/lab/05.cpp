#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
    char *hello = "Hello World!";
    char goodbye[15] = "Goodbye World!";
    string str = "I'm another string";
    
    // Print the messages
    cout << "Hello message: " << hello << endl;
    cout << "Goodbye message: " << goodbye << endl;
    cout << "String: " << str << endl;
    
    // Get sizes
    cout << "Size of hello: " << sizeof(hello) << endl;
    cout << "Size of goodbye: " << sizeof(goodbye) << endl;
    cout << "Size of string: " << sizeof(str) << endl;

    // Get string length
    cout << "Length of hello: " << strlen(hello) << endl;
    cout << "Length of goodbye: " << strlen(goodbye) << endl;
    cout << "Length of string: " << str.length() << endl;
    
    return 0;
}