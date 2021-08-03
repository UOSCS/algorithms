#include <iostream>
#include <cstring>

using namespace std;

int n, arr[100001], count;
bool visited[100001], finished[100001];

void dfs(int current)
{
    visited[current] = true;

    int next = arr[current];

    if(!visited[next])
        dfs(next);
    else if(!finished[next])
    {
        for(int i = next; i != current; i = arr[i])
            count++;
        count++;
    }

    finished[current] = true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;

    cin >> T;

    for(int i = 0; i < T; i++)
    {
        cin >> n;
        for(int j = 1; j <= n; j++)
            cin >> arr[j];

        memset(visited, false, sizeof(visited));
        memset(finished, false, sizeof(finished));
        count = 0;

        for(int j = 1; j <= n; j++)
            if(!visited[j])
                dfs(j);

        cout << n - count << '\n';
    }

    return 0;
}