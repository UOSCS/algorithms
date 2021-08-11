#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> p;

int width, height;
int dh[4] = {-1, 0, 1, 0}, dw[4] = {0, 1, 0, -1};
char matrix[1000][1000];

int bfs(vector<p> &location_of_fires, p &location_of_sang_geun)
{
    int escape_time = 1;
    bool is_visited[1000][1000] = {false};
    queue<p> fire, sang_geun;

    for(p location : location_of_fires)
        fire.push(location);

    sang_geun.push(location_of_sang_geun);
    is_visited[location_of_sang_geun.first][location_of_sang_geun.second] = true;

    while(!sang_geun.empty())
    {
        int size_of_fire_queue = fire.size();

        while(size_of_fire_queue--)
        {
            p current_location = fire.front();

            fire.pop();

            for(int i = 0; i < 4; i++)
            {
                int new_h = current_location.first + dh[i];
                int new_w = current_location.second + dw[i];

                if((new_h < height && new_h >= 0 && new_w < width && new_w >= 0) && 
                   (matrix[new_h][new_w] != '#' && matrix[new_h][new_w] != '*'))
                {
                    matrix[new_h][new_w] = '*';
                    fire.push({ new_h, new_w });
                }
            }
        }

        int size_of_sang_geun_queue = sang_geun.size();

        while(size_of_sang_geun_queue--)
        {
            p current_location = sang_geun.front();

            sang_geun.pop();

            if(current_location.first == 0 || current_location.first == height - 1 || 
               current_location.second == 0 || current_location.second == width - 1)
                return escape_time;

            for(int i = 0; i < 4; i++)
            {
                int new_h = current_location.first + dh[i];
                int new_w = current_location.second + dw[i];

                if(matrix[new_h][new_w] == '.' && !is_visited[new_h][new_w])
                {
                    sang_geun.push({ new_h, new_w });
                    is_visited[new_h][new_w] = true;
                }
            }
        }

        escape_time++;
    }

    return -1;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int T;

    cin >> T;

    for(int i = 0; i < T; i++)
    {
        vector<p> location_of_fires;
        p location_of_sang_geun;

        cin >> width >> height;

        for(int h = 0; h < height; h++)
            for(int w = 0; w < width; w++)
            {
                cin >> matrix[h][w];

                if(matrix[h][w] == '*')
                    location_of_fires.push_back({ h, w });
                if(matrix[h][w] == '@')
                    location_of_sang_geun = { h, w };
            }

        int result = bfs(location_of_fires, location_of_sang_geun);

        if(result < 0)
            cout << "IMPOSSIBLE";
        else
            cout << result;
        cout << '\n';
    }

    return 0;
}