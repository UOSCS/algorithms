#include <iostream>
#include <algorithm>

using namespace std;

int tree[10000];

void post_order(int left, int right)
{
    if(left >= right) return;
    int root = tree[left];
    int mid = upper_bound(tree + left + 1, tree + right, root) - tree;
    post_order(left + 1, mid);
    post_order(mid, right);
    cout << root << '\n';
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i;

    for(i = 0; cin >> tree[i]; i++)
        continue;

    post_order(0, i);

    return 0;
}