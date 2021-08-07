#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

vector<int> v[10001];
bool visited[10001];

void dfs(int current_node, int &number_of_hacked)
{
    number_of_hacked++;
    visited[current_node] = true;

    for(int i = 0; i < v[current_node].size(); i++)
        if(!visited[v[current_node][i]])
            dfs(v[current_node][i], number_of_hacked);
}

int main(void)
{
    int N, M;
    priority_queue<pii> pq;

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int A, B;

        cin >> A >> B;

        v[B].push_back(A);
    }

    for(int i = 1; i <= N; i++)
    {
        int number_of_hacked = 0;

        memset(visited, false, sizeof(visited));

        dfs(i, number_of_hacked);

        pq.push({ number_of_hacked, -i });
    }

    int max_number_of_hacked = pq.top().first;
    while(!pq.empty())
    {
        if(pq.top().first == max_number_of_hacked)
            cout << -pq.top().second << ' ';
        else
            break;
        
        pq.pop();
    }

    return 0;
}