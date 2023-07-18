#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Approach 1: Binary Search
int countNegative1(vector<vector<int>> &grid)
{
    int count = 0;
    int n = grid[0].size();
    // Iterate on all rows of the matrix one by one
    for (auto &row : grid)
    {
        // using binary search (upper_bound ) find the index of the first negative element
        int index = upper_bound(row.begin(), row.end(), 0, greater<int>()) - row.begin();
        // which means n-index is the number of all the nagative element
        count += (n - index);
    }
    return count;
}

// Approach 2: Binary Search no funtionce
int countNegative2(vector<vector<int>> grid)
{
    int count = 0;
    int n = grid[0].size();
    // Iterate on all rows of the matrix one by one
    for (auto row : grid)
    {
        // using binarnegey search find the index
        // which has the first negative element
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (row[mid] < 0)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        count += (n - left);
    }
    return count;
}

// Approach 3: Linear Traversal
int countNegative3(vector<vector<int>> grid)
{
    int count = 0,
        n = grid[0].size(),
        currRowNegativeIndex = n - 1;
    for (auto &row : grid)
    {
        while (row[currRowNegativeIndex] < 0 && currRowNegativeIndex >= 0)
        {
            currRowNegativeIndex--;
        }
        count += (n - (currRowNegativeIndex + 1));
    }
    return count;
}

int main()
{
    vector<vector<int>> grid = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    int param1 = countNegative3(grid);
    cout << param1;
    return 0;
}