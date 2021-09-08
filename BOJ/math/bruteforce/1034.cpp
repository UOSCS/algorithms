#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string input[50];
    int N, M, K, answer = 0;

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> input[i];
    cin >> K;

    for(int i = 0; i < N; i++)
    {
        int zero_count = 0;

        for(int j = 0; j < M; j++)
            if(input[i][j] == '0')
                zero_count++;

        if(zero_count <= K && zero_count % 2 == K % 2)
        {
            int count = 0;

            for(int j = 0; j < N; j++)
                if(input[i] == input[j])
                    count++;

            answer = max(answer, count);
        }
    }

    cout << answer;

    return 0;
}