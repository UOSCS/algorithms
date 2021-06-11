#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int calc(vector<int> &v, int M)
{
    int ret = 0;

    for(int i = 0; i < v.size(); i += M)
        ret += v[i] << 1;

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);

    vector<int> p, m;
    int N, M, answer = 0;

    cin >> N >> M;
    for(int i = 0, tmp; i < N; i++)
    {
        cin >> tmp;
        if(tmp < 0)
            m.push_back(-tmp);
        else
            p.push_back(tmp);
    }

    sort(p.begin(), p.end(), greater<int>());
    sort(m.begin(), m.end(), greater<int>());
    answer += calc(p, M);
    answer += calc(m, M);
    if(p.empty())
        answer -= m[0];
    else if(m.empty())
        answer -= p[0];
    else if(p[0] < m[0])
        answer -= m[0];
    else
        answer -= p[0];

    cout << answer;

    return 0;
}