#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, M;
    char arr[50][50];

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> arr[i][j];

    int answer = 0;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            for(int k = j; k < M; k++)
                if(arr[i][j] == arr[i][k])
                    if((i + k - j >= 0 && i + k - j < N) &&
                       (arr[i + k - j][j] == arr[i][j] && arr[i + k - j][k] == arr[i][k]))
                        answer = max(answer, (k - j + 1) * (k - j + 1));

    cout << answer;

    return 0;
}