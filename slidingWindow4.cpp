#include <iostream>
#include <vector>

using namespace std;

int findBestSubarray(vector<int> nums, int k)
{
    int left = 0, curr = 0;
    for (int i = 0; i < k; i++)
        curr += nums[i];
    int answer = curr;

    for (int i = k; i < nums.size(); i++)
    {
        curr += nums[i] - nums[i - k];
        answer = max(answer, curr);
    }
    return answer;
}

int main()
{

    vector<int> nums = {3, -1, 4, 12, -8, 5, 6};
    int k = 4;
    int pagram = findBestSubarray(nums, k);
    cout << pagram;
    return 0;
}