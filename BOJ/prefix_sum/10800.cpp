#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int>> p;

int main(void)
{
    ios::sync_with_stdio(0);

    vector<p> v;
    int N, p_sum = 0, ans[200001], color[200001] = {0};

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int C, S;
        cin >> C >> S;
        v.push_back({ S, { C, i } });
    }

    sort(v.begin(), v.end());
    for(int i = 0, j = 0; i < v.size(); i++)
    {
        while(v[i].first > v[j].first)
        {
            p_sum += v[j].first;
            color[v[j].second.first] += v[j].first;
            j++;
        }
        ans[v[i].second.second] = p_sum - color[v[i].second.first];
    }

    for(int i = 0; i < N; i++)
        cout << ans[i] << '\n';

    return 0;
}