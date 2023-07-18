#include<iostream>
#include<vector>

using namespace std;

//Approach 1: Using Separate Space
 vector<int> runningSum(vector<int>& nums) {
    vector<int> result = {nums[0]};
    for (int i=1; i<nums.size(); i++)
    {
        result.push_back(result.back()+ nums[i]);
    }
    return result;
    }


int main()
{
   vector<int> nums = {3,1,2,10,1};
   for(int i=0; i<runningSum(nums).size(); i++){
      cout << runningSum(nums)[i]<< " ";
   }
  
    return 0;
}