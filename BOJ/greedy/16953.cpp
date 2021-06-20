#include <iostream>

using namespace std;

int dfs(int a, int b, int n)
{
    if(a > b)
        return 0;
    if(a == b)
        return n;

    int ret = 1234567890, tmp;
    if(a << 1 > 0)
    {
        tmp = dfs(a << 1, b, n + 1);
        if(tmp)
            ret = min(ret, tmp);
    }
    if(a < 1e8)
    {
        tmp = dfs(a * 10 + 1, b, n + 1);
        if(tmp)
            ret = min(ret, tmp);
    }
    return ret == 1234567890 ? 0 : ret;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int A, B, answer;

    cin >> A >> B;

    answer = dfs(A, B, 1);

    cout << (answer ? answer : -1);

    return 0;
}