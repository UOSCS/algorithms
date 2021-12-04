#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N;

    cin >> N;

    vector<pair<int, int>> v;

    for(int i = 0; i < N; i++)
    {
        int tmp;
        
        cin >> tmp;

        v.push_back({ tmp, i });
    }

    sort(v.begin(), v.end());

    int answer = 1, prev = v[0].second;

    for(int i = 1; i < N; i++)
        if(v[i].second > prev)
            answer++, prev = v[i].second;

    cout << answer;

    return 0;
}