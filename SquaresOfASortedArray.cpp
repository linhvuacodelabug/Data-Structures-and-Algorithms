#include <iostream>
#include <vector>
using namespace std;

// Appraoch 1: Two Point
vector<int> sortedSquares1(vector<int> nums)
{
    int left = 0;
    int right = nums.size() - 1;
    int n = nums.size();
    vector<int> result(n);

    while (left <= right)
    {
        int leftSquares = nums[left] * nums[left];
        int rightSquares = nums[right] * nums[right];

        if (leftSquares > rightSquares)
        {
            result[n - 1] = leftSquares;
            left++;
            n--;
        }
        else
        {
            result[n - 1] = rightSquares;
            right--;
            n--;
        }
    }
    return result;
}

// Approach 2: Two Point 1
vector<int> sortedSquares2(vector<int> nums)
{
    int left = 0;
    int right = nums.size() - 1;
    int n = nums.size();
    vector<int> result(n);

    for( int i = n-1; i >= 0; i--)
    {
        if(abs(nums[left]) > abs(nums[right]))
        {
            result[i] = nums[left] * nums[left++];
        }else{
            result[i] = nums[right] * nums[right--];

        }
    }
    return result;
}

int main()
{
    vector<int> nums = {-7,-3,1,3,11};
    for (auto num : sortedSquares2(nums))
        cout << num << " ";
    return 0;
}
