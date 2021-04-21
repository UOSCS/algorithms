#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

queue<tuple<int, int, int>> q;
int N, M, count;
int dn[4] = {-1, 1, 0, 0}, dm[4] = {0, 0, -1, 1};
int is_visited[1000][1000][2];
bool wall[1000][1000];

void bfs()
{
    q.push(make_tuple(0, 0, 0));
    is_visited[0][0][0] = 1;

    while(1)
    {
        int i = q.size();
        if(!i)
        {
            count = -2;
            return;
        }
        while(i--)
        {
            tuple<int, int, int> node = q.front();
            q.pop();

            if(get<0>(node) == N - 1 && get<1>(node) == M - 1)
                return;

            for(int i = 0, new_n, new_m; i < 4; i++)
            {
                new_n = get<0>(node) + dn[i]; new_m = get<1>(node) + dm[i];
                if((new_n >= 0 && new_n < N && new_m >= 0 && new_m < M) && 
                    !is_visited[new_n][new_m][get<2>(node)])
                {
                    if(wall[new_n][new_m])
                    {
                        if(!get<2>(node))
                        {
                            q.push(make_tuple(new_n, new_m, 1));
                            is_visited[new_n][new_m][get<2>(node)] = 1;
                        }
                        else
                            continue;
                    }
                    else
                    {
                        if(get<2>(node))
                        {
                            q.push(make_tuple(new_n, new_m, 1));
                            is_visited[new_n][new_m][get<2>(node)] = 2;
                        }
                        else
                        {
                            q.push(make_tuple(new_n, new_m, 0));
                            is_visited[new_n][new_m][get<2>(node)] = 1;
                        }
                    }
                }
            }
        }
        count++;
    }
}

int main(void)
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0, tmp; j < M; j++)
        {
            scanf("%1d", &tmp);
            if(tmp)
                wall[i][j] = true;
        }

    bfs();
    cout << count + 1 << '\n';

    return 0;
}