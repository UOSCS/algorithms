#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, M;

    cin >> N >> M;

    vector<pair<int, int>> first_race;

    for(int i = 1; i <= N; i++)
    {
        int rank;

        cin >> rank;

        first_race.insert(first_race.begin() + rank - 1, { rank, i });
    }

    vector<int> second_race;

    for(int i = M - 1; i >= 0; i--)
    {
        int rank;

        cin >> rank;

        second_race.insert(second_race.begin() + rank - 1, first_race[i].second);
    }

    for(int i = 0; i < 3; i++)
        cout << second_race[i] << '\n';

    return 0;
}