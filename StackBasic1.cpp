#include <iostream>
#define MAX 100
using namespace std;

struct Stack
{
    int a[MAX]; // mang stack
    int sz = 0; // kich thuoc stack
};

void isEmty(Stack &s)
{
    if (s.sz == 0)
        cout << "Stack is emty!";
}

void push(Stack &s)
{
    int x;
    cout << "\nEnter new value: ";
    cin >> x;
    s.a[s.sz] = x;
    s.sz++;
}

void printS(Stack &s)
{
    for (int i = 0; i < s.sz; i++)
        cout << s.a[i] << " ";
}
void topS(Stack &s)
{
    cout << endl << s.a[s.sz-1]<<endl;
    s.sz--;
}

int main()
{
    Stack s1;
    isEmty(s1);

    for (int i = 0; i < 5; i++)
    {
        push(s1);
    }
    printS(s1);

    topS(s1);
    printS(s1);
    
    return 0;
}