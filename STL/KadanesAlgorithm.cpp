#include <iostream>
#include <vector>
using namespace std;

//Maximum Subarray Sum - Kadane's Algorithm
int maxSubarraySum(vector<int> arr)
{
    int maxEnding =0;
    int result =arr[0];

    for (int i = 0; i< arr.size(); i++)
    {
        maxEnding = max(arr[i], maxEnding+arr[i]);

        result = max(result, maxEnding);
    }
    return result;
}

int main()
{
    vector<int> arr =  {2, 3, -8, 7, -1, 2, 3};
    cout << maxSubarraySum(arr);

    return 0;
}