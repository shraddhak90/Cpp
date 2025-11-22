#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> sortKSortedArry(int arr[], int n, int k)
{
    priority_queue<int , vector<int>, greater<int>> minHeap;
    vector<int> result;

    for (int i =0; i<n ;i++)
    {
        minHeap.push(arr[i]);
        if (minHeap.size()> k)
        {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
    }

    while (!minHeap.empty())
    {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    return result;
}

int main()
{
    int arr[7] = {6,5,3,2,8,10,9};
    int k = 3;
    vector<int> sortedArray = sortKSortedArry(arr, 7, k);

    cout << "Sorted Array: ";
    for (int i =0; i< sortedArray.size(); i++)
    {
        cout << sortedArray[i] << " ";
    }
    cout << endl;
    return 0;
}