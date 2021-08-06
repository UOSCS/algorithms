#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool visited[100001];

pair<int, int> bfs()
{
    queue<int> q;
    int answer = 0, number_of_way = 0;
    bool finished = false;

    q.push(N);
    visited[N] = true;

    while(!q.empty())
    {
        int current_size_of_queue = q.size();
        vector<int> visited_location;
        
        while(current_size_of_queue--)
        {
            int current_location = q.front();
            bool location_plus_1_added = false;

            q.pop();

            if(current_location == K)
            {
                finished = true;
                number_of_way++;
            }

            if(current_location - 1 >= 0 && !visited[current_location - 1])
            {
                q.push(current_location - 1);
                visited_location.push_back(current_location - 1);
            }
            if(current_location + 1 <= 100000 && !visited[current_location + 1])
            {
                q.push(current_location + 1);
                visited_location.push_back(current_location + 1);
            }
            if(current_location << 1 <= 100000 && !visited[current_location << 1])
            {
                q.push(current_location << 1);
                visited_location.push_back(current_location << 1);
            }
        }

        if(finished)
            return { answer, number_of_way };

        answer++;

        for(int tmp : visited_location)
            visited[tmp] = true;
    }

    return { -1, -1 };
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> N >> K;

    pair<int, int> result = bfs();

    cout << result.first << '\n' << result.second;

    return 0;
}