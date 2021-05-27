#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef struct Planet
{
    int idx;
    int x;
    int y;
    int z;
} Planet;

vector<Planet> pv;
vector<pair<int, pair<int, int>>> ev;
int parent[100001];

bool cmp_x(const Planet& a, const Planet& b)
{
    return a.x < b.x;
}
bool cmp_y(const Planet& a, const Planet& b)
{
    return a.y < b.y;
}
bool cmp_z(const Planet& a, const Planet& b)
{
    return a.z < b.z;
}

int find(int node)
{
    if(parent[node] < 0)
        return node;
    return parent[node] = find(parent[node]);
}

bool merge(int a, int b)
{
    a = find(a); b = find(b);
    if(a == b)
        return false;
    parent[a] = b;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, weight = 0;;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        pv.push_back({ i, tmp1, tmp2, tmp3 });
    }

    memset(parent, -1, sizeof(parent));
    sort(pv.begin(), pv.end(), cmp_x);
    for(int i = 0; i < N - 1; i++)
        ev.push_back({ abs(pv[i].x - pv[i + 1].x), { pv[i].idx, pv[i + 1].idx }});
    sort(pv.begin(), pv.end(), cmp_y);
    for(int i = 0; i < N - 1; i++)
        ev.push_back({ abs(pv[i].y - pv[i + 1].y), { pv[i].idx, pv[i + 1].idx }});
    sort(pv.begin(), pv.end(), cmp_z);
    for(int i = 0; i < N - 1; i++)
        ev.push_back({ abs(pv[i].z - pv[i + 1].z), { pv[i].idx, pv[i + 1].idx }});
    sort(ev.begin(), ev.end());
    for(int i = 0; i < ev.size(); i++)
    {
        pair<int, pair<int, int>> tmp = ev[i];
        if(merge(tmp.second.first, tmp.second.second))
            weight += tmp.first;
    }

    cout << weight;

    return 0;
}