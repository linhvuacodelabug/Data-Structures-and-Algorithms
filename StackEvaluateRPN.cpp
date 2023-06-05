#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

string input()
{
    ifstream inputFile("input.txt");
    string str;
    getline(inputFile, str);
    return str;
}
double evaluateRPN(string str)
{
    stack<double> s;

    istringstream iss(str);
    string token;

    while (iss >> token)
    {
        if (isdigit(token[0]))
        {
            double num = stod(token);
            s.push(num);
        }
        else
        {
            double operand2 = s.top();
            s.pop();
            double operand1 = s.top();
            s.pop();

            double result;
            switch (token[0])
            {
            case '+':
            {
                result = operand1 + operand2;
                break;
            }
            case '-':
            {
                result = operand1 - operand2;
                break;
            }
            case '*':
            {
                result = operand1 * operand2;
                break;
            }
            case '/':
            {
                result = operand1 / operand2;
                break;
            }
            }
            s.push(result);
        }
    }
    return s.top();
}
void output(string &str)
{
    ofstream outputFile("output.txt");
    outputFile << evaluateRPN(str);
}
int main()
{
    string str = input();
    output(str);
    return 0;
}