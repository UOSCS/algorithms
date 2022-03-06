//
//  main.cpp
//  cpp
//
//

#include <iostream>

using namespace std;

int arr[20], N, S, answer;

void calc(int depth, int sum, bool flag) {
    if (flag && sum == S) {
        answer++;
        flag = false;
    }
    if (depth == N)
        return;
    
    calc(depth + 1, sum + arr[depth], true);
    calc(depth + 1, sum, flag);
}

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    calc(0, 0, false);
    
    cout << answer;
    
    return 0;
}

