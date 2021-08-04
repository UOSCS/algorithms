#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool visited[100001];

int bfs()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, N });
    visited[N] = true;

    while(!pq.empty())
    {
        pair<int, int> current_node = pq.top();
        int sec = current_node.first, location = current_node.second;

        pq.pop();

        if(location == K)
            return sec;

        if(location << 1 <= 100000 && !visited[location << 1])
        {
            pq.push({ sec, location << 1 });
            visited[location << 1] = true;
        }
        if(location - 1 >= 0 && !visited[location - 1])
        {
            pq.push({ sec + 1, location - 1 });
            visited[location - 1] = true;
        }
        if(location + 1 <= 100000 && !visited[location + 1])
        {
            pq.push({ sec + 1, location + 1 });
            visited[location + 1] = true;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> N >> K;

    cout << bfs();
        
    return 0;
}