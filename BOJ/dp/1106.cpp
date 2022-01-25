//
//  main.cpp
//  cpp
//
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
    
    int C, N;
    
    cin >> C >> N;
    
    vector<pair<int, int>> v;

    for (int i = 0; i < N; i++) {
        int cost, n_guest;
        
        cin >> cost >> n_guest;
        
        v.push_back({ cost, n_guest });
    }
    
    int dp[100001] = {0, };

    for (int i = 0; i < N; i++) {
        for (int j = v[i].first; j <= 100001; j++) {
            int cost = v[i].first, n_guest = v[i].second;
            
            dp[j] = max(dp[j], dp[j - cost] + n_guest);
        }
    }
    
    for (int i = 0; i <= 100001; i++) {
        if (dp[i] >= C) {
            cout << i;
            
            break;
        }
    }
    
    return 0;
}

