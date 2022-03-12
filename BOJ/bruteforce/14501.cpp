//
//  main.cpp
//  cpp
//
//

#include <iostream>

using namespace std;

int N, T[15], P[15], answer;

void calc(int n, int t, int sum) {
    if (n == N) {
        answer = max(answer, sum);
        return;
    }
    
    if (t)
        calc(n + 1, t - 1, sum);
    else if (n + T[n] - 1 >= N)
        calc(n + 1, 0, sum);
    else {
        calc(n + 1, T[n] - 1, sum + P[n]);
        calc(n + 1, 0, sum);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
        
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> T[i] >> P[i];
    
    calc(0, 0, 0);
    
    cout << answer;
    
    return 0;
}

