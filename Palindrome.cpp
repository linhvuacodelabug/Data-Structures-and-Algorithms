#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int input()
{
    ifstream f1("input.txt");
    int x;
    cin >> x;
    return x;
}

// Addroach 1: revert haft of the number
bool isPalindrome(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;
    int revertedNumber = 0;

    // dao nguoc mot nua so nua so
    while (x < revertedNumber)
    {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    return x == revertedNumber || x == revertedNumber / 10;
}

void output(int x)
{
    ofstream f2("output.txt");
    if (isPalindrome(x))
        f2 << "true";
    else
    {
        f2 << "false";
    };
}
int main()
{
    int x = input();
    output(x);
    return 0;
}
