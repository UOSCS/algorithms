//
//  main.cpp
//  cpp
//
//

#include <iostream>
#include <algorithm>

using namespace std;

char mat[5][5];
int answer;
int R, C, K;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
bool is_visited[5][5];

void dfs(int i, int j, int depth) {
    if (depth >= K) {
        if (i == 0 && j == C - 1)
            answer++;
        return;
    }
    
    is_visited[i][j] = true;
    
    for (int k = 0; k < 4; k++) {
        int new_i = i + di[k], new_j = j + dj[k];
        if (new_i < R && new_i >= 0 && new_j < C && new_j >= 0 && mat[new_i][new_j] == '.' && !is_visited[new_i][new_j])
            dfs(new_i, new_j, depth + 1);
    }
    
    is_visited[i][j] = false;
}

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
    
    cin >> R >> C >> K;
    
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> mat[i][j];
    
    dfs(R - 1, 0, 1);
    
    cout << answer;
}

