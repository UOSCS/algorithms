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
    
    int N;
    
    cin >> N;
    
    int A[1001], dp[1001];
    
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    
    fill(dp, dp + N + 1, 1);
    
    int answer = 0;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++)
            if (A[j] > A[i])
                dp[i] = max(dp[i], dp[j] + 1);
        answer = max(answer, dp[i]);
    }
    
    cout << answer;
    
    return 0;
}

