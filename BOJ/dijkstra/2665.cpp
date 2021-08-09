#include <iostream>
#include <queue>

#define INF 1000000000

using namespace std;

typedef pair<int, pair<int, int>> p;

int N, dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
char matrix[50][50];

int dijkstra(int start_row, int start_column)
{
    int distance[50][50];
    priority_queue<p> pq;

    fill(*distance, *distance + 2500, INF);
    distance[start_row][start_column] = 0;
    pq.push({ 0, { start_row, start_column }});

    while(!pq.empty())
    {
        pair<int, int> current_location = pq.top().second;
        int current_distance = -pq.top().first;

        pq.pop();

        if(distance[current_location.first][current_location.second] < current_distance)
            continue;
        
        for(int i = 0; i < 4; i++)
        {
            int new_row = current_location.first + dr[i];
            int new_column = current_location.second + dc[i];
            int current_to_new_distance;

            if(new_row < N && new_row >= 0 && new_column < N && new_column >= 0)
            {
                if(matrix[new_row][new_column] == '0')
                    current_to_new_distance = 1;
                else
                    current_to_new_distance = 0;
            
                if(distance[new_row][new_column] > current_distance + current_to_new_distance)
                {
                    distance[new_row][new_column] = current_distance + current_to_new_distance;
                    pq.push({ -(current_distance + current_to_new_distance), { new_row, new_column }});
                }
            }
        }
    }

    return distance[N - 1][N - 1];
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> matrix[i][j];

    cout << dijkstra(0, 0);

    return 0;
}