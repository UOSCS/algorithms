#include <iostream>

using namespace std;

int  main(void)
{
    ios::sync_with_stdio(0);

    int N, M, cnt[1000] = {0};
    long p_sum[1000001] = {0}, ans = 0;

    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        cin >> p_sum[i];

        p_sum[i] = (p_sum[i - 1] + p_sum[i]) % M;
        if(!p_sum[i])
            ans++;
        cnt[p_sum[i]]++;
    }
    for(int i = 0; i < M; i++)
        ans += ((long)cnt[i] * (cnt[i] - 1)) >> 1;
    
    cout << ans;

    return 0;
}