#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::getline;
using std::stoi;
using std::endl;
using std::setw;
using std::setfill;
using std::string;
using std::vector;

struct student
{
    unsigned int id;
    string name;
    string address;
};

void print_student(student s)
{
    cout << setw(12) << setfill('0') << s.id << setfill(' ');
    cout << setw(30) << s.name;
    cout << setw(40) << s.address;
    cout << endl;
}

student read_student()
{
    student s;
    string tmp;
    cout << "Enter id: ";
    getline(cin, tmp);
    s.id = stoi(tmp);
    cout << "Enter name: ";
    getline(cin, s.name);
    cout << "Enter address: ";
    getline(cin, s.address);
    return s;
}

int main(int argc, char **argv)
{
    vector<student> students;
    for (int i = 0; i < 10; ++i)
    {
        students.push_back(read_student());
    }
    cout << setw(12) << "ID Number";
    cout << setw(30) << "Name";
    cout << setw(40) << "Address";
    cout << endl;
    for (auto s : students)
    {
        print_student(s);
    }
    return 0;
}