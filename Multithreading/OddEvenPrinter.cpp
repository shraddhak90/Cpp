#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;

class OddEvenPrinter
{
    private:
     int maxNum;
     int num;
     mutex mtx;
     condition_variable cv;

    public:
    
    OddEvenPrinter(int max) :num(1), maxNum(max) {}

    void printOddNum()
    {
        while (true)
        {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return (num%2 == 1) || (num > maxNum); });

            if (num > maxNum)
            {
                return;
            }

            cout <<num <<" ";
            num++;
            cv.notify_all();
        }
    }

    void printEvenNum()
    {
        while(true)
        {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return (num%2 == 0) || (num >maxNum); });

            if (num >maxNum)
            {
                return;
            }

            cout << num <<" ";
            num++;
            cv.notify_all();
        }        
    }
};

int main()
{
    OddEvenPrinter printer(10);

    thread t1(&OddEvenPrinter::printOddNum, &printer);
    thread t2(&OddEvenPrinter::printEvenNum, &printer);

    t1.join();
    t2.join();
    return 0;
}

