#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string words[50];
    int N;

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> words[i];

    sort(words, words + N);

    int answer = 0;

    for(int i = 0; i < N; i++)
    {
        bool flag = true;

        for(int j = i + 1; j < N; j++)
            if(!words[j].find(words[i]))
            {
                flag = false;

                break;
            }

        if(flag)
            answer++;
    }

    cout << answer;

    return 0;
}