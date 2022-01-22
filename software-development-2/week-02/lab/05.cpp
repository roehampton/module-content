#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::sort;

int main(int argc, char **argv)
{
    vector<string> data;
    for (int i = 0; i < 10; ++i)
    {
        string str;
        cout << "Enter data: ";
        cin >> str;
        data.push_back(str);
    }
    cout << "Sorting..." << endl;
    sort(data.begin(), data.end());
    for (string str : data)
    {
        cout << str << endl;
    }
    return 0;
}