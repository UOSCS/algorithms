#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    pair<int, int> cur[15], ans[15];

    for(int i = 0; i < 15; i++)
        ans[i].first = i >> 2, ans[i].second = i % 4;

    for(int i = 0; i < 16; i++)
    {
        char c;

        cin >> c;

        if(c == '.') continue;

        cur[c - 'A'].first = i >> 2, cur[c - 'A'].second = i % 4;
    }

    int scatter = 0;

    for(int i = 0; i < 15; i++)
        scatter += abs(ans[i].first - cur[i].first) + abs(ans[i].second - cur[i].second);

    cout << scatter;

    return 0;
}