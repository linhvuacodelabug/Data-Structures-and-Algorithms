#include <iostream>
#include <string>

using namespace std;

int findLeght(string str)
{
    int left = 0, curr = 0, answer = 0;
    for (int right = 0; right < str.length(); right++)
    {
        if (str[right] == '0')
        {
            curr++;
        }
        while (curr > 1)
        {
            left++;
            if (str[left] == '0')
                curr--;
        }
        answer = max(answer, right - left + 1);
    }
    return answer;
}

int main()
{
    string str = "101";
    int param = findLeght(str);
    cout << param;
    return 0;
}