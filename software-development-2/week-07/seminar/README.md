# Software Development 2 Seminar 7 -- Code Understanding

In this seminar, the plan is for students to work out what some obfuscated code does. Have the students split into groups and use the following code fragments **one at a time.** Put the code on the main screen and let the students spend at least 20 minutes discussing it before bringing them back to report their findings.

## Exercise One

```c++
#include <iostream>

using std::cout;
using std::cin;

int main() 
{
  int year;
  cout << "Enter a year: ";
  cin >> year;

  if (year % 400 == 0) 
  {
    cout << year << " Yes";
  }
  else if (year % 100 == 0) 
  {
    cout << year << " No";
  }
  else if (year % 4 == 0) 
  {
    cout << year << " Yes";
  }
  else 
  {
    cout << year << " No";
  }

  return 0;
}
```

## Exercise Two

```cpp
#include <iostream>

using std::cout;
using std::cin;

bool check(int n) 
{
  if (n == 0 || n == 1) 
  {
    return false;
  }
  for (int i = 2; i <= n / 2; ++i) 
  {
    if (n % i == 0) 
    {
      return false;
    }
  }
  return true;
}

int main(int argc, char **argv) 
{
  int n;
  cout << "Enter a positive integer: ";
  cin >> n;
  if (check(n))
    cout << n << " Yes";
  else
    cout << n << " No";
  return 0;
}
```

## Exercise Three

```c++
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

long long convert(int n) 
{
  long long output = 0;
  int rem, i = 1;
  while (n != 0) 
  {
    rem = n % 2;
    n /= 2;
    output += rem * i;
    i *= 10;
  }
  return output;
}

int main() 
{
  int n, output;
  cout << "Enter a decimal number: ";
  cin >> n;
  output = convert(n);
  cout << n << " = " << output << endl ;
  return 0;
}
```

## Exercise Four

This one is complicated, so have the students approach each function in turn and report back.

```c++
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::uniform_int_distribution;
using std::default_random_engine;
using std::random_device;

vector<int> F001(int V001) 
{ 
    random_device V002;
    default_random_engine V003(V002());
    uniform_int_distribution<int> V004;
    vector<int> V005;
	for (int V006 = 0; V006 < V001; ++V006) 
    { 
        V005.push_back(V004(V003));
    } 
    return V005; 
}

void F002(vector<int> &V001) 
{ 
    for (int V002 = 0; V002 < V001.size(); ++V002) 
    {
		for (int V003 = 0; V003 < V001.size() - (V002 + 1); ++V003) 
        {
			if (V001[V003] > V001[V003 + 1]) 
            { 
                int V004 = V001[V003 + 1]; 
                V001[V003 + 1] = V001[V003]; 
                V001[V003] = V004; 
            }
        }
		if (V002 % 1000 == 0) 
        { 
            cout << ((float)V002 / (float)V001.size()) * 100.0f << "% sorted" << endl; 
        }
    }
}

void F003(const string &V001, vector<int> &V002) 
{ 
    ofstream V003(V001);
	for (int &V004 : V002) 
    { 
        V003 << V004 << endl; 
    } 
    V003.close(); 
}

vector<int> F004(const string &V001) 
{ 
    vector<int> V002; 
    ifstream V003(V001);
	while (!V003.eof()) 
    { 
        int V004; 
        V003 >> V004; 
        V002.push_back(V004); 
    } 
    return V002; 
}

int main(int argc, char **argv)
{ 
    vector<int> V001 = F001(65536);
    F003("numbers.txt", V001);
    F002(V001);
    vector<int> V002 = F004("numbers.txt");
	for (int V003 = 0; V003 < 100; ++V003)
    { 
        cout << V001[V003] << "\t" << V002[V003] << endl; 
    } 
    return 0;
}
```

