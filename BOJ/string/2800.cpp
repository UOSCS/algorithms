#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

bool is_valid[200];
vector<pair<int, int>> v;
set<string> visited;
string g_s;

string get_str()
{
    string ret = "";

    for(int i = 0; i < g_s.length(); i++)
        if(is_valid[i])
            ret += g_s[i];

    return ret;
}

void dfs(int depth)
{
    if(depth < 0)
    {
        string str = get_str();
        if(visited.find(str) == visited.end())
            visited.insert(str);
        return;
    }

    pair<int, int> p = v[depth];
    dfs(depth - 1);
    is_valid[p.first] = is_valid[p.second] = false;
    dfs(depth - 1);
    is_valid[p.first] = is_valid[p.second] = true;
}

int main(void)
{
    ios::sync_with_stdio(0);

    stack<int> st;

    cin >> g_s;
    for(int i = 0; i < g_s.length(); i++)
    {
        if(g_s[i] == '(')
            st.push(i);
        if(g_s[i] == ')')
        {
            int left_idx = st.top();
            st.pop();
            v.push_back({ left_idx, i });
        }
    }

    fill(is_valid, is_valid + 200, true);
    visited.insert(g_s);
    dfs(v.size() - 1);
    for(string l_s : visited)
        if(g_s != l_s)
            cout << l_s << '\n';

    return 0;
}