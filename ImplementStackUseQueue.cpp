#include<iostream>
#include<queue>

using namespace std;

class MyStack
{
private:
    queue<int> q1, q2;
public:
    MyStack(){

    }

//Push element x onto stack
    void push(int x)
    {
        q1.push(x);
    }
//Remove element on top of the stack 
    int pop()
    {
        while(q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int top=q1.front();
        q1.pop();

        queue<int> temp=q1;
        q1=q2;
        q2=temp;        
        return top;
    }
//Return whether tack is empty
    bool isEmty()
    {
        return !q1.empty();
    }
//Get the top element
    int top()
    {
        return q1.back();
    }


};
int main()
{
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    
    int pargam2 = obj->pop();
    int pargam3 = obj->top();
    bool pargam4 = obj->isEmty();
    cout << pargam2<< pargam3<< pargam4<< obj->isEmty();
/*
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
    return 0;
}