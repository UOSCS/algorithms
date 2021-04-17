#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> graph[101];
bool is_visited[101];
stack<int> s;
int count;

void dfs(int start_node)
{
    s.push(start_node);
    is_visited[start_node] = true;
    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        count++;
        for(int i = 0, tmp; i < graph[node].size(); i++)
        {
            tmp = graph[node][i];
            if(!is_visited[tmp])
            {
                s.push(tmp);
                is_visited[tmp] = true;
            }
        }
    }
}

int main(void)
{
    int num_of_com, num_of_edge;

    cin >> num_of_com >> num_of_edge;
    for(int i = 0, node1, node2; i < num_of_edge; i++)
    {
        cin >> node1 >> node2;
        graph[node1].push_back(node2); graph[node2].push_back(node1);
    }
    dfs(1);
    cout << count - 1 << '\n';

    return 0;
}