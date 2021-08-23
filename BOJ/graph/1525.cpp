#include <iostream>
#include <queue>
#include <map>

using namespace std;

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
map<string, bool> visited;

int bfs(string start)
{
    queue<string> q;
    string target = "123456789";
    int depth = 0;

    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        int current_size = q.size();

        while(current_size--)
        {
            string current = q.front();

            q.pop();

            if(current == target)
                return depth;
            
            int idx = current.find('9');
            int i = idx / 3, j = idx % 3;
            
            for(int k = 0; k < 4; k++)
            {
                int next_i = i + di[k], next_j = j + dj[k];

                if(next_i >= 0 && next_i < 3 && next_j >= 0 && next_j < 3)
                {
                    string tmp = current;

                    swap(tmp[idx], tmp[next_i * 3 + next_j]);

                    if(!visited[tmp])
                    {
                        visited[tmp] = true;
                        q.push(tmp);
                    }
                }
            }
        }

        depth++;
    }

    return -1;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int start = 0;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            int tmp;
            cin >> tmp;
            if(!tmp)
                tmp = 9;
            start = start * 10 + tmp;
        }
    
    cout << bfs(to_string(start));

    return 0;
}
