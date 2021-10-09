#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, M;
    char matrix[50][50];
    bool row[50], col[50];

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> matrix[i][j];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(matrix[i][j] == 'X')
                row[i] = true, col[j] = true;

    int answer = 0;

    for(int i = 0; i < N; i++)
        if(!row[i])
        {
            row[i] = true, answer++;
            
            for(int j = 0; j < M; j++)
                if(!col[j])
                {
                    col[j] = true;

                    break;
                }
        }

    for(int i = 0; i < M; i++)
        if(!col[i])
            answer++;

    cout << answer;

    return 0;
}