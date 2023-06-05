#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

void INPUT(vector<int> &arr, int &target)
{
    cin >> target;
    int num;
    while (cin >> num)
    {
        arr.push_back(num);
    }
}

void OUTPUT(vector<int> &arr)
{
    freopen("outp.txt", "w", stdout);
    for (const auto &num : arr)
    {
        cout << num << " ";
    }
    fclose(stdout);
}

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashmap;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (hashmap.count(complement) > 0) {
            return {i, hashmap[complement]};
        }
        hashmap[nums[i]] = i;
    }
    return {};
}
int main()
{
    vector<int> arr;
    int target;
    // doc file
    freopen("inp.txt", "r", stdin);
    INPUT(arr, target);
    fclose(stdin);

    // xuat file
    vector<int> result = twoSum(arr, target);
    OUTPUT(result);

    return 0;
}
