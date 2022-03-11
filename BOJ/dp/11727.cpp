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
        
    int n;
    
    cin >> n;
    
    int dp[1001] = {0, };
    
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = ((dp[i - 2] << 1) + dp[i - 1]) % 10007;
    
    cout << dp[n];
    
    return 0;
}

