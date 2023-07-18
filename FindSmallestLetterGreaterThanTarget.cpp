#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// ==========Approach 1: Brute Force
char  nextGreatestLetter1(vector<char> letters, char target)
{
    for (auto letter : letters){
        if (letter > target){
            return letter;
        }
    }
    return letters[0];
}

// ==========Approach 2: Binary Search
char nextGreatestLetter2(vector<char> letters, char target)
{
    int left = 0;
    int right = letters.size()-1;
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (letters[mid] <= target)
        {
            left = mid + 1;
        }else{
            right = mid -1;
        }
    }
    return (left == letters.size()) ? letters[0] : letters[left];
}

int main()
{
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'c';
        cout << nextGreatestLetter2(letters, target);
    return 0;
}