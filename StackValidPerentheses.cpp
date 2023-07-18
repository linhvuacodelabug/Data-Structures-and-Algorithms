#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isValid(string str)
{
    if (str.length()==0) return true;

    stack<int> s;
    for(auto itr:str)
    {
        if (itr == '('||itr == '['||itr == '{' ) s.push(itr);
        else{
            if(s.empty() || abs(itr - s.top()) >2) return false;
                else s.pop();
        }
    } 
    return s.empty();

}

int main()
{
    string str="((({{}}))";
    cout << isValid(str);
    return 0;
}

