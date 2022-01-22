#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template<typename T>
T my_add(T left, T right)
{
    return left + right;
}

int main(int argc, char **argv)
{
    auto num = my_add(5, 4);
    cout << "num = " << num << endl;
    auto str = my_add(string("Hello, "), string("world!"));
    cout << "str = " << str << endl;
    auto num2 = my_add(5.0f, 10.0f);
    cout << "num2 = " << num2 << endl;
    auto logic = my_add(true, false);
    cout << "logic = " << logic << endl;
    return 0;
}