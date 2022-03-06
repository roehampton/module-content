#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using std::cout; using std::cin; using std::getline; using std::stoi; using std::endl; using std::setw;
using std::setfill; using std::string; using std::vector;
struct S001 { unsigned int V001; string V002; string V003; };
void F001(S001 s) { cout << setw(12) << setfill('0') << s.V001 << setfill(' ') << setw(30) << s.V002 << setw(40) << s.V003 << endl; }
S001 F002() { S001 s; string V001;
cout << "Enter id: "; getline(cin, V001); s.V001 = stoi(V001);
cout << "Enter name: "; getline(cin, s.V002);
cout << "Enter address: "; getline(cin, s.V003); return s; }
int main(int argc, char **argv) { vector<S001> V001;
for (int i = 0; i < 10; ++i) { V001.push_back(F002()); }
cout << setw(12) << "ID Number" << setw(30) << "Name" << setw(40) << "Address" << endl;
for (auto s : V001) { F001(s); } return 0; }