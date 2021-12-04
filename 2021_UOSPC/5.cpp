#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, x[100001], y[100001];
    bool xb[100001] = {false}, yb[100001] = {false};

    cin >> N;

    for(int i = 1; i <= N; i++)
        cin >> x[i];
    for(int i = 1; i <= N; i++)
        cin >> y[i];

    int count = 0;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            if(!xb[i] && !yb[j] && x[i] * i == y[j] * j) count++, xb[i] = yb[j] = true;

    cout << count;

    return 0;
}