#include <iostream>
#include <thread>

using namespace std;

void do_work()
{
    cout << "I'm a thread!" << endl;
}

int main(int argc, char **argv)
{
    // Create a thread running do_work
    thread thr(do_work);
    cout << "I'm the main program!" << endl;
    // Join the thread
    thr.join();
    return 0;
}