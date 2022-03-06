#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
using std::cout; using std::endl; using std::string; using std::vector; using std::ifstream; using std::ofstream;
using std::uniform_int_distribution; using std::default_random_engine; using std::random_device;
vector<int> F001(int V001) { random_device V002; default_random_engine V003(V002()); uniform_int_distribution<int> V004; vector<int> V005;
for (int V006 = 0; V006 < V001; ++V006) { V005.push_back(V004(V003)); } return V005; }
void F002(vector<int> &V001) { for (int V002 = 0; V002 < V001.size(); ++V002) {
for (int V003 = 0; V003 < V001.size() - (V002 + 1); ++V003) {
if (V001[V003] > V001[V003 + 1]) { int V004 = V001[V003 + 1]; V001[V003 + 1] = V001[V003]; V001[V003] = V004; }}
if (V002 % 1000 == 0) { cout << ((float)V002 / (float)V001.size()) * 100.0f << "% sorted" << endl; }}}
void F003(const string &V001, vector<int> &V002) { ofstream V003(V001);
for (int &V004 : V002) { V003 << V004 << endl; } V003.close(); }
vector<int> F004(const string &V001) { vector<int> V002; ifstream V003(V001);
while (!V003.eof()) { int V004; V003 >> V004; V002.push_back(V004); } return V002; }
int main(int argc, char **argv) { vector<int> V001 = F001(65536); F003("numbers.txt", V001); F002(V001); vector<int> V002 = F004("numbers.txt");
for (int V003 = 0; V003 < 100; ++V003) { cout << V001[V003] << "\t" << V002[V003] << endl; } return 0; }