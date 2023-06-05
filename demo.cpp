#include <iostream>
#include <math.h>
using namespace std;

void input(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void ouput(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    // input
    input(a, n);

    // output
    ouput(a, n);
    cout << endl;

    // sort
    sort(a, n);

    // output
    ouput(a, n);

    return 0;
}