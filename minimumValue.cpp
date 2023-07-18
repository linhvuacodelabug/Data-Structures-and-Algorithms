#include <iostream>
#include <vector>

using namespace std;

// Approach 1: brute force check from 1 to which alement will satisfy then condition
int minStartValue1(vector<int> nums)
{
    int startValue = 1;
    int sum = 0, i = 0;
    while (1)
    {
        sum = startValue;
        int stop = 0;
        for (auto num : nums)
        {
            sum += num;
            if (sum < 1)
            {
                startValue++;
                sum = 0;
                break;
            }
            stop++;
        }
        // kiem tra da chay hoan chinh 1 vong ma ko gap so < 1
        if (stop == nums.size())
        {
            break;
        }
    }
    return startValue;
}

// Approack 2: prefix sum
int minStartValue2(vector<int> nums)
{
    int sum = 0, minPrefSum = 0;
    for (auto num : nums)
    {
        sum += num;
        minPrefSum = min(minPrefSum, sum);
    }
    return 1 - minPrefSum;
}

int main()
{
    vector<int> nums = {1, -2, -3};
    int pagram = minStartValue2(nums);
    cout << pagram;
    return 0;
}
