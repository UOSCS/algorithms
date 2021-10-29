#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N;
    char mat[100][100];

    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> mat[i][j];

    int count_row = 0, count_col = 0;

    for(int i = 0; i < N; i++)
    {
        int count = 0;

        for(int j = 0; j < N; j++)
        {
            if(mat[i][j] == '.') count++;
            else count = 0;

            if(count == 2) count_row++;
        }
    }

    for(int i = 0; i < N; i++)
    {
        int count = 0;

        for(int j = 0; j < N; j++)
        {
            if(mat[j][i] == '.') count++;
            else count = 0;
            
            if(count == 2) count_col++;
        }
    }

    cout << count_row << ' ' << count_col;

    return 0;
}