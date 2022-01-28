#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::numeric_limits;
using std::setw;

template<typename T>
void print_type(string type)
{
    cout << setw(20) << type;
    cout << setw(8) << sizeof(T);
    cout << setw(25) << +numeric_limits<T>::min();
    cout << setw(25) << +numeric_limits<T>::max();
    cout << endl;
}

int main(int argc, char **argv)
{
    cout << setw(20) << "Type" << setw(8) << "Size" << setw(25) << "Min" << setw(25) << "Max" << endl;
    print_type<unsigned char>("unsigned char");
    print_type<char>("char");
    print_type<unsigned short>("unsigned short");
    print_type<short>("short");
    print_type<unsigned int>("unsigned int");
    print_type<int>("int");
    print_type<unsigned long>("unsigned long");
    print_type<long>("long");
    print_type<unsigned long long>("unsigned long long");
    print_type<long long>("long long");
    print_type<float>("float");
    print_type<double>("double");
    print_type<long double>("long double");
    
    return 0;
}