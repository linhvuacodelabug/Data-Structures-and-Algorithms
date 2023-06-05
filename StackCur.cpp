#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

string input()
{
    ifstream f1("input.txt");
    string str;
    getline(f1, str);
    return str;
}

int priority(string &c)
{
    if (c == "+" || c == "-")
        return 1;
    return 2;
}

void process(stack<double> &val, string op)
{
    double op2 = val.top();
    val.pop();
    double op1 = val.top();
    val.pop();
    
    //chuyen string ve char (tao nghe noi switch dung string hong duoc)
    // istringstream iss(op);
    // char opc;
    // iss >> opc;

    switch(op[0])
    {
    case '+':
        val.push(op1 + op2);
        break;
    case '-':
        val.push(op1 - op2);
        break;
    case '*':
        val.push(op1 * op2);
        break;
    case '/':
        val.push(op1 / op2);
        break;
    }
}

double evaluate(string &str)
{
    stack<double> val; // luu toan hang value
    stack<string> op;  // luu toan tu operand

    istringstream iss(str);
    string token;

    while (iss >> token)
    {
        if (isdigit(token[0]))
        {
            double num = stod(token);
            val.push(num);
        }
        else
        {
            string cur_op = token; // luu ky tu hien tai 
            // xu ly toan tu truoc no co do uu tien lon hon hoac bang
            while (!op.empty() && priority(op.top()) >= priority(cur_op))
            {
                process(val, op.top());
                op.pop();
            }
            op.push(cur_op);
        }
    }

    //sau khi duyet het chuoi ta con toan tu cuoi can xu ly
    while (!op.empty())
    {
        process(val, op.top());
        op.pop();
    }
    return val.top();
}

void output(string &str)
{
    ofstream f2("output.txt");
    f2 << evaluate(str);
}


int main()
{
    string str = input();
    output(str);
    return 0; 
}