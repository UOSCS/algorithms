#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int arr[5];

    for(int i = 0; i < 5; i++)
        cin >> arr[i];

    int answer = 1000000;

    for(int i = 0; i < 3; i++)
        for(int j = i + 1; j < 4; j++)
            for(int k = j + 1; k < 5; k++)
            {
                int multiple = arr[i];

                while(true)
                    if(!(multiple % arr[j]) && !(multiple % arr[k])) break;
                    else multiple += arr[i];

                answer = min(answer, multiple);
            }

    cout << answer;

    return 0;
}
