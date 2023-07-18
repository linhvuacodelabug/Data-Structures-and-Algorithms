#include <iostream>
#include <vector>

using namespace std;

vector<int> getAverages(vector<int> nums, int k)
{
    int n = nums.size();
    vector<int> avg(n, -1);
    vector<long long> prefix(n + 1);

    // khi k=0 no kieu kieu 0/0... vo nghia
    if (k == 0)
    {
        return nums;
    }

    // (k x 2 + 1) vuot qua n thi cung vuc thoi
    if ((k * 2 + 1) > n)
    {
        return avg;
    }

    // Tao prefix sum
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    // gio thi moi chuyen chi moi bat dau ne
    for (int i = k; i < n - k; i++)
    {
        int leftBound = i - k;
        int rightBound = i + k;
        long long subArraySum = 0;
        subArraySum = prefix[rightBound + 1] - prefix[leftBound];
        avg[i] = subArraySum / (k * 2 + 1);
    }

    return avg;
}
int main()
{
    vector<int> nums = {7, 4, 3, 9, 1, 8, 5, 2, 6};
    int k = 3;
    for (auto num : getAverages(nums, k))
    {
        cout << num << " ";
    }
    return 0;
}