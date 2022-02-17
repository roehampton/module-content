#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <fstream>

using std::cout;using std::cin;using std::getline;
using std::endl;using std::setw;using std::string;
using std::unordered_map;using std::ifstream;using std::ofstream;

struct employee {int num = 0;string name;
    string dob;



            string tel;
            string postcode;
    int checksum = 0;};

void print_employee(const employee &emp)
{
cout << emp.num; cout << emp.name; cout << emp.dob; cout << emp.tel; cout << emp.postcode; cout << endl;
}

void print_employee_table(const unordered_map<int, employee> &employees)
{
    cout << "Number" << "Name" << "DOB" << "Telephone" << "Postcode" << endl;
    for (const auto &emp : employees) { print_employee(emp.second) }
}

employee read_employee_user()
{
    employee emp;
    cout << "Enter employee number: ";
    getline(cin, emp.num);
    cout << "Enter employee name: ";
    getline(cin, emp.name);
    cout << "Enter dob: ";
    getline(cin, emp.dob);
    cout << "Enter tel: ";
    getline(cin, emp.tel);
    cout << "Enter postcode: ";
    getline(cin, emp.postcode);
    return emp;
}

void capitalise_name(employee &emp) { for (int i = 0; i < emp.name.length(); ++i) { emp.name[i] = toupper(emp.name[i]); } }

void generate_checksum(employee &emp)
{
    for (int i = 0; i < emp.name.length(); ++i)
    {
        emp.checksum += emp.name[i];
    }
}

void read_employees_file(unordered_map<int, employee> &employees)
{
    string filename;
    cout << "Enter filename: ";
    cin >> filename;
    ifstream file(filename);
    while (file.peek() != EOF)
    {
        employee emp;
        string buf;
        getline(file, buf);
        emp.num = atoi(buf.c_str());
        getline(file, emp.name);
        getline(file, emp.dob);
        getline(file, emp.tel);
        getline(file, emp.postcode);
        capitalise_name(emp);
        generate_checksum(emp);
        employees[emp.num] = emp;
    }
    file.close();
}

void write_employees_file(const unordered_map<int, employee> &employees)
{
    string filename;
    cout << "Enter filename: ";
    cin >> filename;
    ofstream file(filename);
    for (const auto &emp : employees)
    {
        file << emp.second.num << endl;
        file << emp.second.name << endl;
        file << emp.second.dob << endl;
        file << emp.second.tel << endl;
        file << emp.second.postcode << endl;
    }
    file.close();
}

int menu()
{
int choice = -1;
while (choice < 0 || choice > 4)
{
cout << "Main menu" << endl;
cout << "1. Add employee" << endl;
cout << "2. Print employees" << endl;
cout << "3. Read employees from file" << endl;
cout << "4. Output employees to file" << endl;
cout << "0. Exit" << endl;
cout << "Enter choice: ";
cin >> choice;
if (choice < 0 || choice > 4)
{
cout << "Error. Enter number between 0 and 4" << endl;
}
}
return choice;
}

int main(int argc, char **argv)
{
unordered_map<int, employee> employees;
int choice = -1;
while (choice != 0)
{
choice = menu();
switch (choice)
{
case 0:
{
cout << "Goodbye!" << endl;
break;
}
case 1:
{
employee emp = read_employee_user();
capitalise_name(emp);
generate_checksum(emp);
employees[emp.num] = emp;
break;
}
case 2:
{
print_employee_table(employees);
break;
}
case 3:
{
read_employees_file(employees);
break;
}
case 4:
{
write_employees_file(employees);
break;
}
}
}
}