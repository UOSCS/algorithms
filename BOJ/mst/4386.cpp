#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

typedef pair<double, pair<int, int>> KS;
typedef pair<pair<double, double>, int> p;

int parent[100];
vector<p> arr;
vector<KS> edge;

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

    int n;
    double weight = 0.0;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        double v1, v2;
        cin >> v1 >> v2;
        arr.push_back({ { v1, v2 }, i });
    }

    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
        {
            double dist = sqrt(pow(arr[i].first.first - arr[j].first.first, 2) + pow(arr[i].first.second - arr[j].first.second, 2));
            edge.push_back({ dist, { arr[i].second, arr[j].second }});
        }


    memset(parent, -1, sizeof(parent));
    sort(edge.begin(), edge.end());
    for(int i = 0; i < edge.size(); i++)
    {
        KS e = edge[i];
        if(merge(e.second.first, e.second.second))
            weight += e.first;
    }

    cout << fixed; cout.precision(2);
    cout << weight;

    return 0;
}