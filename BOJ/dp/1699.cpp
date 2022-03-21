//
//  main.cpp
//  cpp
//
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
    
    int N, dp[100001] = {0, };
    
    cin >> N;
        
    for (int i = 1; i <= N; i++) {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
    
    cout << dp[N];
    
    return 0;
}

