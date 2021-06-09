#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> p;

int main(void)
{
    ios::sync_with_stdio(0);

    vector<p> v;
    int N, score = 0;
    bool flag[1001] = {false};

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int d, w;
        cin >> d >> w;
        v.push_back({ w, d });
    }

    sort(v.begin(), v.end(), greater<p>());
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = v[i].second; j >= 1; j--)
            if(!flag[j])
            {
                flag[j] = true;
                score += v[i].first;
                break;
            }
    }

    cout << score;

    return 0;
}