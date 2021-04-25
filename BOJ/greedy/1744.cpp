#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int result;

void calc(vector<int> v)
{
    while(v.size() > 1)
    {
        int tmp1 = *(v.end() - 1); v.pop_back();
        int tmp2 = *(v.end() - 1); v.pop_back();
        result += tmp1 * tmp2;
    }
    if(v.size())
        result += v[0];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    vector<int> v_for_plus, v_for_minus;

    cin >> N;
    for(int i = 0, tmp; i < N; i++)
    {
        cin >> tmp;
        if(tmp == 1)
            result++;
        else if(tmp > 0)
            v_for_plus.push_back(tmp);
        else
            v_for_minus.push_back(tmp);
    }

    sort(v_for_plus.begin(), v_for_plus.end());
    sort(v_for_minus.begin(), v_for_minus.end(), greater<int>());
    calc(v_for_plus);
    calc(v_for_minus);

    cout << result << '\n';

    return 0;
}