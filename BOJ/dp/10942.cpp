#include <iostream>

using namespace std;

bool dp_cache[2000][2000];

void fill_dp_cache(int *arr, int N)
{
    for(int i = 1; i <= N; i++)
        dp_cache[i][i] = 1;
    for(int i = 1; i < N; i++)
        if(arr[i] == arr[i + 1])
            dp_cache[i][i + 1] = 1;
    for(int gap = 2; gap < N; gap++)
        for(int start = 1; start + gap <= N; start++)
        {
            int end = start + gap;
            if(arr[start] == arr[end] && dp_cache[start + 1][end - 1])
                dp_cache[start][end] = 1;
        }
}

void print_result(pair<int, int> *p, int M)
{
    for(int i = 1; i <= M; i++)
        cout << dp_cache[p[i].first][p[i].second] << '\n';
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, *arr, M;
    pair<int, int> *p;

    cin >> N;
    arr = new int[N + 1];
    for(int i = 1; i <= N; i++)
        cin >> arr[i];
    cin >> M;
    p = new pair<int, int>[M + 1];
    for(int i = 1; i <= M; i++)
        cin >> p[i].first >> p[i].second;

    fill_dp_cache(arr, N);
    print_result(p, M);

    return 0;
}