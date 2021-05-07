#include <iostream>

using namespace std;

int N, arr[10001], dp_cache[10001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int min_time = 0;

    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        int num_of_prev_task;
        cin >> arr[i] >> num_of_prev_task;
        for(int j = 0; j < num_of_prev_task; j++)
        {
            int tmp;
            cin >> tmp;
            dp_cache[i] = max(dp_cache[i], dp_cache[tmp]);
        }
        dp_cache[i] += arr[i];
        min_time = max(min_time, dp_cache[i]);
    }

    cout << min_time << '\n';

    return 0;
}