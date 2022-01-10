#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string name;

    cin >> name;

    int N;

    cin >> N;

    string arr[50];

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    int max_p_win = 0;

    string answer = arr[0];

    for(int i = 0; i < N; i++)
    {
        string str_concat = name + arr[i];

        int L, O, V, E;

        L = O = V = E = 0;

        for(int j = 0; j < str_concat.length(); j++)
            if(str_concat[j] == 'L') L++;
            else if(str_concat[j] == 'O') O++;
            else if(str_concat[j] == 'V') V++;
            else if(str_concat[j] == 'E') E++;

        int p_win;

        p_win = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;

        if(p_win > max_p_win)
        {
            answer = arr[i];

            max_p_win = p_win;
        }
    }

    cout << answer;

    return 0;
}