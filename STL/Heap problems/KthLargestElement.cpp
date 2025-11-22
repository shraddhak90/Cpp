#include <iostream>
#include <queue>
using namespace std;

int kthLargestElement(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i =0 ;i< n;i++)
    {
        minHeap.push(arr[i]);
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }
    return minHeap.top();
}

int main()
{
    int arr[5] = {7, 10, 4, 3, 20};

    cout << "3rd Largest Element is " << kthLargestElement(arr, 5, 2) << endl;
    return 0;
}