#include <iostream>
#include <string>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

int main(int argc, char **argv)
{
    unordered_map<string, string> lecturers;
    lecturers["Software Development 2"] = "Kevin";
    lecturers["Software Development 1"] = "Arturo";
    lecturers["Databases"] = "Wei";
    lecturers["Computer Systems"] = "Oge";
    for (auto entry : lecturers)
    {
        cout << entry.first << " " << entry.second << endl;
    }
    return 0;
}