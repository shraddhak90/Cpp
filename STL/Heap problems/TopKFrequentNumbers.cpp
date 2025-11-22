#include <iostream>
#include<queue>
#include<vector>
#include <unordered_map>
using namespace std;

vector<int> topKFrequentNumbers(int arr[], int n, int k)
{
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    unordered_map<int, int> freqMap;
    vector<int> result;

    for (int i =0 ;i < n;i++)
    {
        freqMap[arr[i]]++;
    }

    for (auto& itr : freqMap)
    {
        minHeap.push({itr.second, itr.first});
        if (minHeap.size() >k )
        {
            minHeap.pop();
        }
    }

    while (!minHeap.empty())
    {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result;
}

int main()
{
    int arr[14] = {1,1,1,1,2,4,3,2,4,2,3,5,3,5};

    vector<int> result = topKFrequentNumbers(arr, 14, 3);

    cout <<"Result: "<<endl;
    for (auto res : result)
    {
        cout <<res << " ";
    }
}