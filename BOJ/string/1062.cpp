#include <iostream>

using namespace std;

int N, K;
int words[50], visited, answer;

void calc(int idx, int cnt)
{
    if(cnt == K)
    {
        int tmp = 0;
        for(int i = 0; i < N; i++)
            if((words[i] & visited) == words[i])
                tmp++;
        answer = max(answer, tmp);
    }
    else
        for(int i = idx; i < 26; i++)
            if(!(visited & (1 << i)))
            {
                visited |= 1 << i;
                calc(i, cnt + 1);
                visited &= ~(1 << i);
            }
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < tmp.length(); j++)
            words[i] |= 1 << (tmp[j] - 'a');
    }

    if(K < 5)
        cout << 0;
    else
    {
        visited |= 1;
        visited |= 1 << 2;
        visited |= 1 << 8;
        visited |= 1 << 13;
        visited |= 1 << 19;
        calc(0, 5);
        cout << answer;
    }

    return 0;
}