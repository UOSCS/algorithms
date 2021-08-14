#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> p;

int departure, destination;
vector<p> v[10001];
bool visited[10001];

bool bfs(int weight)
{
    queue<int> q;

    q.push(departure);
    visited[departure] = true;

    while(!q.empty())
    {
        int current = q.front();

        q.pop();

        if(current == destination)
            return true;
        
        for(int i = 0; i < v[current].size(); i++)
        {
            int next = v[current][i].first;
            int new_weight = v[current][i].second;

            if(!visited[next] && new_weight >= weight)
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int N, M, max_weight = 0;

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int A, B, C;

        cin >> A >> B >> C;

        v[A].push_back({ B, C }), v[B].push_back({ A, C });
        max_weight = max(max_weight, C);
    }
    cin >> departure >> destination;

    int low = 1, high = max_weight;

    while(low <= high)
    {
        int mid = (low + high) >> 1;

        memset(visited, false, sizeof(visited));

        if(bfs(mid))
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << high;

    return 0;
}