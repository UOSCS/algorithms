#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int T;

    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int n, m, degree[501], diff[501] = {0}, flag = 0;
        vector<int> v;

        cin >> n;
        v.resize(n);
        for(int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            degree[tmp] = j;
        }

        cin >> m;
        while(m--)
        {
            int t1, t2;
            cin >> t1 >> t2;
            if(degree[t1] > degree[t2])
                swap(t1, t2);
            diff[t1]++;
            diff[t2]--;
        }

        for(int j = 1; j <= n; j++)
        {
            degree[j] += diff[j];
            if(v[degree[j]])
            {
                flag = 1;
                break;
            }
            v[degree[j]] = j;
        }

        if(flag)
            cout << "IMPOSSIBLE";
        else
            for(int j : v)
                cout << j << ' ';
        cout << '\n';
    }

    return 0;
}