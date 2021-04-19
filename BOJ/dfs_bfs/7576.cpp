#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
int M, N, arr[1000][1000];
int dn[4] = {-1, 1, 0, 0}, dm[4] = {0, 0, -1, 1};
int count_zero, count_date = 1;

void bfs()
{
    if(q.empty())
    {
        count_date = -1;
        return;
    }

    int i = q.size();
    while(i)
    {
        pair<int, int> node = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int new_n = node.first + dn[i], new_m = node.second + dm[i];
            if((new_n >= 0 && new_n < N && new_m >= 0 && new_m < M) &&
               !arr[new_n][new_m])
            {
                q.push(make_pair(new_n, new_m));
                arr[new_n][new_m] = 1;
                count_zero--;
            }
        }
        i--;
    }
    if(count_zero <= 0)
        return;
    else
    {
        count_date++;
        bfs();
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> M >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if(!arr[i][j])
                count_zero++;
            else if(arr[i][j] == 1)
                q.push(make_pair(i, j));
        }

    if(!count_zero)
        cout << "0\n";
    else
    {
        bfs();
        cout << count_date << '\n';
    }

    return 0;
}