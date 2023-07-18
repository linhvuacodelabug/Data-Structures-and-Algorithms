#include <iostream>
#include <string>
#include<unordered_set>
using namespace std;

// Approach 1: Find lettes one by one
bool checkIfPangram1(string sentence)
{
    for (int i = 0; i < 26; i++)
    {
        char currC = 'a' + i;

        // neu co ky tu nao khong duoc tim thay thi tra ve false
        if (sentence.find(currC) == string::npos)
        {
            return false;
        }
    }
    // da tim thay 26 kytu tra ve true
    return true;
}

//Approach 2: Set
bool checkIfPangram2(string sentence)
{
    // them moi chu cai cua sentence vao set
    unordered_set<char> seen(sentence.begin(), sentence.end());
    // neu seen du 26 chu cai thi do la pangram
    return seen.size()==26;
}

int main()
{
    string str = "thequickbrownfoxjumpsoverthelazydog";
    cout << (checkIfPangram1(str) == 1);
    return 0;
}