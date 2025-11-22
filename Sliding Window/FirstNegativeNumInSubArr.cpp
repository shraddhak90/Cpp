#include <iostream>
#include <vector>
#include <list>
using namespace std;

//arr[] = [-8, 2, 3, -6, 10] , k = 2

vector<int> firstNegInt(vector<int>& arr, int k) 
{
    int i=0,j=0;
    list<int> lt;
    vector<int> negNums;

    while (j <arr.size())
    {
        if (arr[j] < 0)
        {
            lt.push_back(arr[j]);
        }
        
        if (j-i+1 < k)
        {
            j++;
        }
        else if (j -i+1 == k)
        {
            if (lt.empty())
            {
                negNums.push_back(0);
            }
            else
            {
                negNums.push_back(lt.front());
                if (arr[i] == lt.front())
                {
                lt.pop_front();    
                }
            }
            i++;
            j++;
        }
    }
    return negNums;
}

int main()
{
    vector<int> arr = {-8, 2, 3, -6, 10};
    int k = 2;
    vector<int> result = firstNegInt(arr, k);
    cout << "First negative numbers in each subarray of size " << k << " are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}