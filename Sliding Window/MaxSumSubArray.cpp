#include <iostream>
#include <vector>


int maxSubarraySum(std::vector<int>& arr, int k) 
{
    int sum = 0, max =0;
    int i =0, j=0;
    
    while (j < arr.size())
    {
        sum +=arr[j];
        
        if (j-i+1 <k)
        {
            j++;
        }
        else if (j-i+1 == k)
        {
            if (sum  > max)
            {
                max = sum;
            }
            sum = sum - arr[i];
            i++;
            j++;
        }
        
    }
    return max;
}

int main()
{
    std::vector<int> arr = {100, 200, 300, 400};
    int k = 3;
    int result = maxSubarraySum(arr, k);
    std::cout << "Maximum sum of subarray of size " << k << " is: " << result << std::endl;
    return 0;
}