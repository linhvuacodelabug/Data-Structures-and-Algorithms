#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<int> s;
    s.push(1); //them vao stack
    s.push(0);
    s.push(2);

    cout << s.top()<< endl; // in ra dinh
    s.pop(); //loai bo phan tu cuoi
    cout << s.top() << endl; //in ra dinh
    return 0;
}