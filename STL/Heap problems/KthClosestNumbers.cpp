#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kthClosestNumbers(int arr[], int n, int k, int x)
{
    vector<int> result;
    priority_queue<pair<int, int>> maxHeap;

    for (int i=0; i< n;i++)
    {
        maxHeap.push(make_pair(abs(arr[i]-x), arr[i]));

        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }

    while (!maxHeap.empty())
    {
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    return result;
}

int main()
{
    int arr[] = {6,5,3,2,8,10,9};

    vector<int> kthClosestNumber = kthClosestNumbers(arr, 7, 3, 7);

    cout << "Kth Closest numbers: ";
    for (int i =0; i< kthClosestNumber.size(); i++)
    {
        cout << kthClosestNumber[i] << " ";
    }
    cout << endl;
    return 0;
}