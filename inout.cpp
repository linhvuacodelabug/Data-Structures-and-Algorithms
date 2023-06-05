#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string input()
{
    ifstream f1("input.txt");
    string str;
    getline(f1, str);
    return str;
}

void output(string &str)
{
    ofstream f2("output.txt");
    f2 << str;
}

int main()
{
    string str = input();
    output(str);
    return 0; 
}
