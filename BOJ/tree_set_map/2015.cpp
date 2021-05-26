#include <iostream>
#include <map>

using namespace std;

int p_sum[200001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<int, int> m;
    long long count = 0;
    int N, K;

    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        int tmp;
        cin >> tmp;
        p_sum[i] = p_sum[i - 1] + tmp;
    }

    for(int i = 1; i <= N; i++)
    {
        if(p_sum[i] == K)
            count++;
        count += m[p_sum[i] - K];
        m[p_sum[i]]++;
    }

    cout << count;

    return 0;
}