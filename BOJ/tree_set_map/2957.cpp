#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    map<int, long long> m;
    long long count = 0;
    int N;

    m.insert({ 0, 0 });
    m.insert({ 300001, 0 });
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        map<int, long long>::iterator itr, tmp;
        int key;
        cin >> key;
        m[key] = 0;
        if(i)
        {
            tmp = itr = m.find(key);
            count += m[key] = max((--itr)->second, (++tmp)->second) + 1;
        }
        cout << count << '\n';
    }

    return 0;
}