#include <iostream>
#include <vector>

using namespace std;

vector<int> v[50];
int delete_node, count;

void dfs(int node)
{
    if(node == delete_node)
        return;
    if(!v[node].size())
    {
        count++;
        return;
    }
    if(v[node].size() == 1 && v[node][0] == delete_node)
    {
        count++;
        return;
    }
    for(int i = 0; i < v[node].size(); i++)
        dfs(v[node][i]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, root;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int parent;
        cin >> parent;
        if(parent != -1)
            v[parent].push_back(i);
        else
            root = i;
    }
    cin >> delete_node;

    dfs(root);

    cout << count << '\n';

    return 0;
}