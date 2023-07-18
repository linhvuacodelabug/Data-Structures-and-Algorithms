#include <iostream>
#include <vector>
#include<deque>
using namespace std;

// Approach 1: Monotonic Deque
vector<int> maxSlidingWindow(vector<int> nums, int k)
{
    deque<int> dq;
    vector<int> res;

    //chay vong k dau tien
    for(int i=0; i<k;  i++)
    {
        while(!dq.empty() && nums[i] >= nums[dq.back()]) // nums lon hon hoac bang gia tri cuoi dq
        {
            dq.pop_back(); //xoa phan tu dau tien dq
        }
        dq.push_back(i); // them i vao cuoi dq
    }
    res.push_back(nums[dq.front()]); // dua gia tri dau tien tu dq vao res
    
    //chay nhung vong k tiep theo
    for(int i =k; i<nums.size(); i++)
    {
        if (dq.front() == i-k){ // khi nao vong lap chay qua font dq thi loai font
            dq.pop_front();
        }
        while(!dq.empty() && nums[i] >= nums[dq.back()]){ 
            dq.pop_back();
        }
        dq.push_back(i);
        res.push_back(nums[dq.front()]);
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    for (auto num : maxSlidingWindow(nums, k))
    {
        cout << num << " ";
    }
    return 0;
}