#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

void do_work()
{
    cout << "I'm a thread!" << endl;
}

int main(int argc, char **argv)
{
    thread thr(do_work);
    cout << "I'm the main program!" << endl;
    thr.join();
    return 0;
}