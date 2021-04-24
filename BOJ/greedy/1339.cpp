#include <iostream>
#include <algorithm>

using namespace std;

int N, alpha[26];
string words[10];

int greedy()
{
    int result = 0;

    for(int i = 0; i < N; i++)
    {
        int value = 1;
        for(int j = words[i].length() - 1; j >= 0; j--)
        {
            int tmp = words[i][j] - 'A';
            alpha[tmp] += value;
            value *= 10;
        }
    }
    sort(alpha, alpha + 26, greater<int>());
    for(int i = 0, num = 9; alpha[i]; i++, num--)
        result += alpha[i] * num;
    
    return result;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> words[i];

    cout << greedy() << '\n';

    return 0;
}