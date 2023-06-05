#include <iostream>
using namespace std;

class customStack
{
public:
    int sz = 0; // kich thuoc tack
    int a[1000];    // mang tack

    // them phan tu vao tack
    void push()
    {
        int x;
        cin >> x;
        a[sz] = x;
        sz++;
    }

    // xoa phan tu khoi tack
    void pop()
    {
        if (sz)
            sz--;
    }

    // lay gia tri cuoi trong tack
    int top()
    {
        if (sz)
            return a[sz - 1];
    }

    // lay kich thuoc tack
    int getSize()
    {
        return sz;
    }
};

int main()
{
    customStack T;
    T.push();
    
    return 0;
}