// Adapted from https://www.geeksforgeeks.org/program-generate-random-alphabets/
#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 52;
 
// Returns a string of random alphabets of
// length n.
string printRandomString(int n)
{
    char alphabet[MAX] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
                          'o','p','q','r','s','t','u','v','w','x','y','z','A','B',
                          'C','D','E','F','G','H','I','J','K','L','M','N','O','P',
                          'Q','R','S','T','U','V','W','X','Y','Z' };
    string res = "";
    for (int i = 0; i < n; i++)
        res = res + alphabet[rand() % MAX];
    return res;
}
int main()
{
   srand ( time(NULL) );     
   int n = 9;
   for (int i=0;i<10;i++)
    cout << printRandomString(n) << "\n";
   return 0;
}
