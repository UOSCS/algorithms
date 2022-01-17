#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N;

    cin >> N;

    char arr[150];

    for(int i = 0; i < N; i++)
    {
        string tmp;

        cin >> tmp;

        arr[i] = tmp[0];
    }

    sort(arr, arr + N);

    int count = 1;

    char prev = arr[0];

    string answer = "";

    for(int i = 1; i < N; i++)
    {
        if(prev == arr[i]) count++;
        else 
        {
            if(count >= 5)
                answer += prev;

            count = 1;
        }

        prev = arr[i];
    }

    if(count >= 5)
        answer += prev;

    if(answer.length()) cout << answer;
    else cout << "PREDAJA";

    return 0;
}