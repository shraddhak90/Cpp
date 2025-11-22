#include<iostream>
#include <queue>
#include<vector>
#include<unordered_map>
using namespace std;


priority_queue<pair<int,int>> frequencySort(int arr[], int n)
{
    priority_queue<pair<int,int>> maxHeap;

    unordered_map<int, int> map;

    for(int i =0;i<n;i++)
    {
        map[arr[i]]++;
    }

    for (auto& itr : map)
    {
        maxHeap.push({itr.second, itr.first});
    }
    return maxHeap;
}

int main()
{
    int arr[10] = {6, 5, 4, 2, 4, 2, 1, 2, 1, 1};

    priority_queue<pair<int,int>> maxHeap = frequencySort(arr, 10);

    while(!maxHeap.empty())
    {
        auto freq = maxHeap.top();
        for (int i =0; i<freq.first; i++)
        {
            cout <<freq.second <<" ";
        }
        cout<<endl;
        maxHeap.pop();
    }
}