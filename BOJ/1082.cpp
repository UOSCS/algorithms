#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, M, p[50], min_cost = 50, min_value;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> p[i];

        if(min_cost > p[i])
        {
            min_cost = p[i];

            min_value = i;
        }
    }
    cin >> M;

    int answer[50], idx = 0;

    while(M >= min_cost)
    {
        answer[idx++] = min_value;

        M -= min_cost;
    }

    int most_sig_num = idx - 1;

    for(int i = idx - 1; i >= 0; i--)
    {
        for(int j = N - 1; j >= 0; j--)
            if(M + min_cost >= p[j])
            {
                answer[i] = j;

                M += min_cost - p[j];

                break;
            }
        
        if(!answer[most_sig_num])
        {
            most_sig_num--;

            M += min_cost;
        }
    }

    if(most_sig_num < 0)
        cout << 0;
    else
        for(int i = most_sig_num; i >= 0; i--)
            cout << answer[i];

    return 0;
}