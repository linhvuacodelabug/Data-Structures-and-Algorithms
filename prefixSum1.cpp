#include <iostream>
#include <strstream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    int n, t;
    int nums[100];
    int sum[100];
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sum[0] = nums[0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + nums[i];
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        cout << sum[y] - sum[x] << endl;
    }
    return 0;
}