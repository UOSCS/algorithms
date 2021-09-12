#include <iostream>
#include <cmath>

using namespace std;

bool is_square_number(int n)
{
    return pow((int) sqrt(n), 2) == n;
}

int solve(int N, int M, char arr[][9], int answer)
{
    for(int n = 0; n < N; n++)
        for(int m = 0; m < M; m++)
            for(int i = -N; i <= N; i++)
                for(int j = -M; j <= M; j++)
                {
                    if(!i && !j) continue;

                    int current_n = n, current_m = m;
                    int current_value = 0;

                    while(current_n >= 0 && current_n < N && current_m >= 0 && current_m < M)
                    {
                        current_value = current_value * 10 + (arr[current_n][current_m] - '0');

                        if(is_square_number(current_value))
                            answer = max(answer, current_value);

                        current_n += i, current_m += j;
                    }
                }

    return answer;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int N, M;
    char arr[9][9];

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> arr[i][j];

    cout << solve(N, M, arr, -1);

    return 0;
}