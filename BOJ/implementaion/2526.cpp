#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, P;
    int arr[97] = {0};

    cin >> N >> P;

    int count = 0, n = N, i = 0;

    while(true)
    {
        n = (n * N) % P;

        if(arr[n]) 
        {
            count = i - arr[n];
            
            break;
        }
        else
            arr[n] = i, count++;
        
        i++;
    }

    cout << count;

    return 0;
}