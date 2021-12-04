#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int T;

    cin >> T;

    while(T--)
    {
        int N, M;

        cin >> N >> M;

        long long N_arr[200000];

        long long N_sum = 0, M_sum = 0;

        for(int i = 0; i < N; i++)
        {
            cin >> N_arr[i];

            N_sum += N_arr[i];
        }
        
        for(int i = 0; i < M; i++)
        {
            int tmp;

            cin >> tmp;
            
            M_sum += tmp;
        }

        int count = 0;

        for(int i = 0; i < N; i++)
            if(N_arr[i] * N < N_sum && N_arr[i] * M > M_sum) count++;

        cout << count << '\n';
    }

    return 0;
}