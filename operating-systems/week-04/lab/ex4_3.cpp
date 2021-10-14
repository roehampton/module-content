#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

void sleeper(int duration)
{
    // Wake up every duration
    for (int i = 0; i < 10; ++i)
    {
        cout << this_thread::get_id() << " awake!" << endl;
        cout << this_thread::get_id() << " going to sleep" << endl;
        this_thread::sleep_for(milliseconds(duration));
    }
}

int main(int argc, char **argv)
{
    thread t1(sleeper, 2000);
    thread t2(sleeper, 3000);
    t1.join();
    t2.join();
    return 0;
}