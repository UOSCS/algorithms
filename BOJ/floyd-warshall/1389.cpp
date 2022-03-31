//
//  main.cpp
//  cpp
//
//

#include <iostream>

#define INF 100

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
    
    int N, M;
    
    cin >> N >> M;
    
    int d[101][101];
    
    fill(*d, *d + 101 * 101, INF);
    for (int i = 1; i <= N; i++)
        d[i][i] = 0;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        d[a][b] = 1;
        d[b][a] = 1;
    }
    
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
    
    int max_sum = INF, answer = 0;
    
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++)
            sum += d[i][j];
        if (max_sum > sum) {
            answer = i;
            max_sum = sum;
        }
    }
    
    cout << answer;
    
    return 0;
}

