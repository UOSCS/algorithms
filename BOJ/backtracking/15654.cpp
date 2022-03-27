//
//  main.cpp
//  cpp
//
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, arr[8];
bool flag[8];
vector<int> v;

void calc(int n) {
    
    if (n == M) {
        for (int num : v)
            cout << num << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
        if (!flag[i]) {
            v.push_back(arr[i]);
            flag[i] = true;
            calc(n + 1);
            v.pop_back();
            flag[i] = false;
        }
}

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
        
    cin >> N >> M;
    
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    sort(arr, arr + N);
    
    calc(0);
    
    return 0;
}

