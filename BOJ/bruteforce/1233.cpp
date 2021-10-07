#include <iostream>
#include <map>
#include <algorithm>


using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int S1, S2, S3;
    map<int, int> m;

    cin >> S1 >> S2 >> S3;

    for(int i = 1; i <= S1; i++)
        for(int j = 1; j <= S2; j++)
            for(int k = 1; k <= S3; k++)
                m[i + j + k]++;

    cout << min_element(m.begin(), m.end(), [](const auto& l, const auto& r) { return l.second > r.second; })->first;

    return 0;
}