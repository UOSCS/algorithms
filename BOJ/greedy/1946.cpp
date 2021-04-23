#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr;
    int T;

    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int N, threshold, count = 1;
        
        cin >> N;
        arr.resize(N + 1);
        for(int j = 0, tmp1, tmp2; j < N; j++)
        {
            cin >> tmp1 >> tmp2;
            arr[tmp1] = tmp2;
        }

        threshold = arr[1];
        for(int j = 2; j <= N; j++)
            if(arr[j] < threshold)
            {
                count++;
                threshold = arr[j];
            }

        cout << count << '\n';
    }

    return 0;
}