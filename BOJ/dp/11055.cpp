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
    
    int N, arr[1001] = {0, }, dp[1001] = {0, };
    
    cin >> N;
    
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    
    copy(arr, arr + N + 1, dp);
    
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++)
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + arr[i]);
        answer = max(answer, dp[i]);
    }
    
    cout << answer;
    
    return 0;
}

