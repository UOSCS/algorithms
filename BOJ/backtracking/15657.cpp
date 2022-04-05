//
//  main.cpp
//  cpp
//
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, arr[10000];
vector<int> v;

void solve(int idx, int depth) {
    if (depth >= M) {
        for (int i : v)
            cout << i << ' ';
        cout << '\n';
        return;
    }
    
    for (int i = idx; i < N; i++) {
        v.push_back(arr[i]);
        solve(i, depth + 1);
        v.pop_back();
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    sort(arr, arr + N);
    solve(0, 0);
    
    return 0;
}

