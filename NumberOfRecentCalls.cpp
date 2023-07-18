#include<iostream>
#include<queue>
using namespace std;

class RecentCounter
{
private:
    queue<int> q;
public:
    RecentCounter(){
    }
    int ping(int t)
    {
        q.push(t);
        while(q.front() < t-3000)
        {
            q.pop();
        }
        return q.size();
    }
};
int main()
{
    RecentCounter* obj = new RecentCounter();
    int param1 = obj->ping(1);
    int param2 = obj->ping(100);
    int param3 = obj->ping(3001);
    int param4 = obj->ping(3002);
    cout << param1 ;
    cout << param2 ;
    cout << param3 ;
    cout << param4 ;

    return 0;
}