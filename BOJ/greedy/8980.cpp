#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<pair<int, int>, int> p;

int main(void)
{
    ios::sync_with_stdio(0);

    vector<p> v;
    int N, C, M, total = 0, arr_w[2001] = {0};

    cin >> N >> C >> M;
    for(int i = 0; i < M; i++)
    {
        int dep, dest, weight;
        cin >> dep >> dest >> weight;
        v.push_back({ { dest, dep }, weight });
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
        int start = v[i].first.second, end = v[i].first.first, max_w = 0;
        for(int j = start; j < end; j++)
            max_w = max(max_w, arr_w[j]);
        if(max_w < C)
        {
            int add = min(C - max_w, v[i].second);
            for(int j = start; j < end; j++)
                arr_w[j] += add;
            total += add;
        }
    }

    cout << total;

    return 0;
}