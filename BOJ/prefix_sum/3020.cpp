#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, H, ans, n = 0;
    vector<int> a, b;

    cin >> N >> H;
    for(int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        i & 1 ? b.push_back(tmp) : a.push_back(tmp);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ans = N;
    for(int i = 1; i <= H; i++)
    {
        int num_of_obs = 0;
        num_of_obs += a.end() - lower_bound(a.begin(), a.end(), i);
        num_of_obs += b.end() - upper_bound(b.begin(), b.end(), H - i);
        if(num_of_obs < ans)
        {
            n = 1;
            ans = num_of_obs;
        }
        else if(num_of_obs == ans)
            n++;
    }

    cout << ans << ' ' << n;

    return 0;
}