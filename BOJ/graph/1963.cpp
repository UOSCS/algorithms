#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool is_prime[10000];

void init_is_prime()
{
    memset(is_prime, true, sizeof(is_prime));

    for(int i = 2; i < 10000; i++)
        for(int j = i << 1; j < 10000; j += i)
            is_prime[j] = false;
}

int bfs(int start_number, int end_number)
{
    queue<int> q;
    int number_of_conversion = 0;
    bool is_visited[10000] = {false};

    q.push(start_number);
    is_visited[start_number] = true;

    while(!q.empty())
    {
        int current_queue_size = q.size();

        while(current_queue_size--)
        {
            int current_number = q.front();

            q.pop();

            if(current_number == end_number)
                return number_of_conversion;

            string current_number_string = to_string(current_number);
            
            for(int i = 0; i < 4; i++)
                for(int j = 0; j < 10; j++)
                {
                    if(!i && !j)
                        continue;

                    string next_number_string = current_number_string;

                    next_number_string[i] = j + '0';

                    int next_number = stoi(next_number_string);

                    if(is_prime[next_number] && !is_visited[next_number])
                    {
                        q.push(next_number);
                        is_visited[next_number] = true;
                    }
                }
        }

        number_of_conversion++;
    }

    return -1;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int T;

    cin >> T;

    init_is_prime();

    for(int i = 0; i < T; i++)
    {
        int start_number, end_number;

        cin >> start_number >> end_number;

        int result = bfs(start_number, end_number);

        if(result < 0)
            cout << "impossible";
        else
            cout << result;
        cout << '\n';
    }

    return 0;
}