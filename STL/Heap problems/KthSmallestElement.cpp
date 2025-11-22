#include <iostream>
#include <queue>
using namespace std;

int kthSmallestElement(int arr[], int n , int k)
{
    priority_queue<int> maxHeap;

    for (int i =0 ; i< n; i++)
    {
        maxHeap.push(arr[i]);
        if (maxHeap.size() >k)
        {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}

int main()
{
    int arr[5] = {7, 10, 4, 3, 20};

    cout << "3rd Smallest Element is " << kthSmallestElement(arr, 5, 3) << endl;
    return 0;
}