#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N;

    cin >> N;
    
    int answer = 0;

    while(N--)
    {
        int arr[3];

        cin >> arr[0] >> arr[1] >> arr[2];

        sort(arr, arr + 3);

        int eq_count = 0, prev = arr[0];

        for(int i = 1; i < 3; i++)
        {
            if(prev == arr[i]) eq_count++;

            prev = arr[i];
        }

        int price;

        if(eq_count == 2) price = 10000 + arr[0] * 1000;
        else if(eq_count == 1) price = 1000 + arr[1] * 100;
        else price = 100 * arr[2];

        answer = max(answer, price);
    }

    cout << answer;

    return 0;
}