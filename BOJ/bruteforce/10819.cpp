//
//  main.cpp
//  cpp
//
//

#include <iostream>
#include <vector>

using namespace std;

int N, arr[8], answer;
bool flag[8];
vector<int> v;

void calc(int n) {
    
    if (n == N) {
        int sum = 0, prev = v[0];
        for (int i = 1; i < v.size(); i++) {
            sum += abs(v[i] - prev);
            prev = v[i];
        }
        answer = max(answer, sum);
        return;
    }
    
    for (int i = 0; i < N; i++) {
        if (!flag[i]) {
            flag[i] = true;
            v.push_back(arr[i]);
            calc(n + 1);
            flag[i] = false;
            v.pop_back();
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
        
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    calc(0);
    
    cout << answer;
    
    return 0;
}

