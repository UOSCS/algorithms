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
    
    int N, M;
    
    cin >> N >> M;
    
    int A[10001] = {0, };
    
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] = A[i - 1] + A[i];
    }
    
    int low = 0, high = 1, answer = 0;
    
    while (true) {
        if (high == N && low == N)
            break;
        
        int interval_sum = A[high] - A[low];
        
        if(high < N && interval_sum < M)
            high++;
        else {
            if (interval_sum == M)
                answer++;
            low++;
        }
    }
    
    cout << answer;
    
    return 0;
}

