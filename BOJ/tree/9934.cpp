#include <iostream>
#include <vector>

using namespace std;

vector<int> level[11];
int tree[1024];

void calc(int K, int lev, int left)
{
    if(!K)
        return;
    int bias = (1 << (K - 1)) - 1;
    level[lev].push_back(tree[left + bias]);
    calc(K - 1, lev + 1, left);
    calc(K - 1, lev + 1, left + bias + 1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int K;

    cin >> K;
    for(int i = 0; i < (1 << K) - 1; i++)
        cin >> tree[i];
    
    calc(K, 1, 0);

    for(int i = 1; i <= K; i++)
    {
        for(int j = 0; j < level[i].size(); j++)
            cout << level[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}