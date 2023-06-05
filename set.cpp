#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> arr;
int n;

void InpArr()
{
    cin>> n;
    arr.resize(n);
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
}

void OutArr()
{
    for (const auto& num : arr){
        cout << num << " ";
    }
}

void findDuplicates()
{
    unordered_map<int, int> countMap;
    // dem so lan xuat hien cua tung phan tu trong mang
    for(int num : arr){
        countMap[num]++;
    }
    
    // in ra cac phan tu lap lai trong mangpa
    cout << "cac phan tu lap lai: ";
    for(const auto& pair : countMap){
        if (pair.second> 1){
            cout << pair.first << " ";
        }
    }
    cout << endl;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    InpArr();
    fclose(stdin);

    //findDuplicates();

    freopen("outp.txt", "w", stdout);
    findDuplicates();
    fclose(stdout);

    return 0;
}