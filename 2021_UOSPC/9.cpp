#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int N;
long long answer;

void calc(int seq)
{
    vector<int> tmp = v;
    int count = 0;
    int n = v.size();

    for(int i = 0; i < N; i++)
        if(tmp[i] == seq)
        {
            count++;

            seq++;

            v.erase(v.begin() + i);
        }

    answer += (n - count) << 1;

    if(v.size())
        calc(seq);
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int tmp;

        cin >> tmp;

        v.push_back(tmp);
    }

    calc(1);

    answer += (N << 1);

    cout << answer;

    return 0;
}