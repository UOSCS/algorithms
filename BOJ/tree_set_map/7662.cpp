#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;

    cin >> T;
    for(int i = 0; i < T; i++)
    {
        multiset<int> ms;
        int k;
        cin >> k;
        for(int j = 0; j < k; j++)
        {
            char c;
            int n;
            cin >> c >> n;
            if(c == 'I')
                ms.insert(n);
            else if(c == 'D')
            {
                if(ms.empty())
                    continue;
                if(n == 1)
                    ms.erase(--ms.end());
                else
                    ms.erase(ms.begin());
            }
        }
        if(ms.empty())
            cout << "EMPTY\n";
        else
            cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
    }

    return 0;
}