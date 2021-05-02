#include <iostream>

using namespace std;

int N, K, coin[100], dp_cache[10001];

void dp()
{
    dp_cache[0] = 1;
    for(int i = 0; i < N; i++)
        for(int j = coin[i]; j <= K; j++)
            dp_cache[j] += dp_cache[j - coin[i]];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> coin[i];
    
    dp();
    cout << dp_cache[K];

    return 0;
}