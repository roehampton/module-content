#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void print_id()
{
    cout << "My ID is " << this_thread::get_id() << endl;
}

int main(int argc, char **argv)
{
    vector<thread> threads;

    // Launch 100 threads
    for (int i = 0; i < 100; ++i)
    {
        threads.push_back(thread(print_id));
    }
    // Print a message
    cout << "I'm the main program!" << endl;
    // Join 100 threads
    for (int i = 0; i < 100; ++i)
    {
        threads[i].join();
    }
    return 0;
}