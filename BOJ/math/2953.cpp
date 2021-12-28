#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int winner = 0, max_score = 0;

    for(int i = 1; i <= 5; i++)
    {
        int score_sum = 0;

        for(int j = 0; j < 4; j++)
        {
            int score;

            cin >> score;

            score_sum += score;
        }

        if(max_score < score_sum)
        {
            winner = i;

            max_score = score_sum;
        }
    }

    cout << winner << ' ' << max_score;

    return 0;
}