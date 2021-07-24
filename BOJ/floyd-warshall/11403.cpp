#include <iostream>

using namespace std;

bool mat[100][100];

int main(void)
{
    ios::sync_with_stdio(0);

    int N;

    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> mat[i][j];
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                if(mat[j][i] && mat[i][k])
                    mat[j][k] = true;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cout << mat[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}