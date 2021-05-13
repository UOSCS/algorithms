#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;

    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int N, M;
        cin >> N >> M;
        for(int j = 0; j < M; j++)
        {
            int a, b;
            cin >> a >> b;
        }
        cout << N - 1 << '\n';
    }

    return 0;
}