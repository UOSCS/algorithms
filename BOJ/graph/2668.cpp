#include <iostream>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

int second_row[101];
set<int> result;
vector<int> trace;
bool is_visited[101], is_in_set[101];

void dfs(int current, int start)
{
    if(is_visited[current])
    {
        if(current == start)
            for(int i = 0; i < trace.size(); i++)
            {
                result.insert(trace[i]);
                is_in_set[trace[i]] = true;
            }
    }
    else
    {
        is_visited[current] = true;
        trace.push_back(current);
        dfs(second_row[current], start);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);

    int N;

    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> second_row[i];

    for(int i = 1; i <= N; i++)
    {
        memset(is_visited, false, sizeof(is_visited));
        trace.clear();

        if(!is_in_set[i])
            dfs(i, i);
    }

    cout << result.size() << '\n';
    for(int i : result)
        cout << i << '\n';

    return 0;
}