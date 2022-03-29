//
//  main.cpp
//  cpp
//
//

#include <iostream>
#include <vector>

using namespace std;

int N;
bool flag[9];
vector<int> v;

void calc(int n) {
    
    if (n >= N) {
        for (int i : v)
            cout << i << ' ';
        cout << '\n';
        return;
    }
    
    for (int i = 1; i <= N; i++)
        if (!flag[i]) {
            v.push_back(i);
            flag[i] = true;
            calc(n + 1);
            v.pop_back();
            flag[i] = false;
        }
}

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
    
    cin >> N;
    
    calc(0);
    
    return 0;
}

