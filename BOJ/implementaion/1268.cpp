#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, arr[1000][5];

    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < 5; j++)
            cin >> arr[i][j];

    int answer = -1, max_count = -1;

    for(int i = 0; i < N; i++)
    {
        bool flag[N] = {false};
        int count = 0;

        for(int j = 0; j < 5; j++)
            for(int k = 0; k < N; k++)
                if(i != k && arr[i][j] == arr[k][j] && !flag[k])
                    flag[k] = true, count++;

        if(max_count < count)
            answer = i + 1, max_count = count;
    }

    cout << answer;

    return 0;
}