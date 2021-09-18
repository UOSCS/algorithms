#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N;
    char matrix[50][50];

    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> matrix[i][j];

    int answer = 0;

    for(int i = 0; i < N; i++)
    {
        int count = 0;

        for(int j = 0; j < N; j++)
        {
            if(i == j) continue;

            if(matrix[i][j] == 'Y' && matrix[j][i] == 'Y')
                count++;
            else
                for(int k = 0; k < N; k++)
                    if(matrix[i][k] == 'Y' && matrix[j][k] == 'Y')
                    {
                        count++;

                        break;
                    }
        }

        answer = max(answer, count);
    }

    cout << answer;

    return 0;
}