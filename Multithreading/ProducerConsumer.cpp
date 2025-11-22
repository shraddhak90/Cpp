#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

std::queue<int> queue;
std::mutex m;
std::condition_variable cv;
const unsigned int maxBufferSize = 10;
bool done = false;

void producer()
{
  for (int i =0; i< maxBufferSize;i++)
  {
    std::unique_lock<std::mutex> lock(m);
	queue.push(i);
	std::cout << "Produced " << i<< std::endl;
	lock.unlock();
    cv.notify_one();
  }
  done = true;
  cv.notify_one();
}

void consumer()
{
  while(true)
  {
    std::unique_lock<std::mutex> lock(m);
    cv.wait(lock, []{ return !queue.empty() || done; }); 
    if (!queue.empty())
	{
	  int val = queue.front();
	  queue.pop();
      std::cout <<"consumed " << val<<std::endl;
	}
	else if (done)
	{
	 break;
	}
  }
}

int main()
{
    std::thread prodThread(producer);
    std::thread consumerThread(consumer);

    prodThread.join();
    consumerThread.join();

    return 0;
}