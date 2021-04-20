#include <iostream>
#include <queue>

#define MAX_SIZE 100000

using namespace std;

queue<int> q;
int N, K, count;
bool is_visited[MAX_SIZE + 1];

void bfs()
{
    q.push(N);
    is_visited[N] = true;
    while(1)
    {
        int i = q.size();
        while(i--)
        {
            int node = q.front();
            q.pop();
            if(node == K)
                return;
            if(node - 1 >= 0 && !is_visited[node - 1])
            {
                q.push(node - 1);
                is_visited[node - 1] = true;
            }
            if(node + 1 <= MAX_SIZE && !is_visited[node + 1])
            {
                q.push(node + 1);
                is_visited[node + 1] = true;
            }
            if((node << 1) <= MAX_SIZE && !is_visited[node << 1])
            {
                q.push(node << 1);
                is_visited[node << 1] = true;
            }
        }
        count++;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    bfs();
    cout << count << '\n';

    return 0;
}