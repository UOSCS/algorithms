#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, start = 301, end = 301, answer = 0;
    vector<pair<int, int>> v;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int t1, t2, t3, t4;
        cin >> t1 >> t2 >> t3 >> t4;
        v.push_back({ t1 * 100 + t2, t3 * 100 + t4 });
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
        if(end >= 1201)
            break;
        if(v[i].first <= start && v[i].second > end)
        {
            answer++;
            while(i < v.size() && v[i].first <= start)
            {
                if(v[i].second > end)
                    end = v[i].second;
                i++;
            }
            if(i == v.size())
                break;
            start = end;
            i--;
        }
    }
    if(end < 1201)
        answer = 0;

    cout << answer;

    return 0;
}