#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// A data structure containing student information
struct student
{
    unsigned int id;
    string name;
    string address;
};

// Prints student information
void print_student(student s)
{
    cout << "id: " << s.id << endl;
    cout << "name: " << s.name << endl;
    cout << "address: " << s.address << endl;
}

int main(int argc, char **argv)
{
    // Output size of the struct
    cout << "Size of student struct is " << sizeof(student) << endl;
    // Create a student data structure
    student s;
    s.id = 1234;
    s.name = "Kevin Chalmers";
    s.address = "School of Arts";
    // Print student data
    print_student(s);
    return 0;
}