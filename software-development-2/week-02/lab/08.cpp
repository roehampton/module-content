#include <iostream>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::random_device;
using std::uniform_int_distribution;

int main(int argc, char **argv)
{
    random_device random;
    uniform_int_distribution<int> distribution(1, 50);
    auto answer = distribution(random);
    int guess = -1;
    while (guess != answer)
    {
        cout << "Enter guess: ";
        cin >> guess;
        if (guess < answer)
        {
            cout << "Too low" << endl;
        }
        else if (guess > answer)
        {
            cout << "Too high" << endl;
        }
        else
        {
            cout << "Correct!" << endl;
            break;
        }
    }
    return 0;
}