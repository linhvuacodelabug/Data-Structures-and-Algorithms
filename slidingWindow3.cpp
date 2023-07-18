#include <iostream>
#include <vector>

using namespace std;

int findLengt(vector<int> nums, int k)
{
    int left = 0, curr = 1, answer = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        curr *= nums[right];
        while (curr >= k)
        {
            curr /= nums[left];
            left++;
        }
        answer += right - left +1;
    }
    return answer;
}

int main()
{
    vector<int> nums={10, 5, 2, 6};
    int k=100;
    int pagram = findLengt(nums, k);
    cout << pagram;
    return 0;
}
