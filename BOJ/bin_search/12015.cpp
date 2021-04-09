#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v;
    int N;

    cin >> N;
    for(int i = 0, tmp; i < N; i++)
    {
        cin >> tmp;
        if(v.empty() || v.back() < tmp)
            v.push_back(tmp);
        else
        {
            auto index = lower_bound(v.begin(), v.end(), tmp);
            *index = tmp;
        }
    }
    cout << v.size() << endl;

    return 0;
}