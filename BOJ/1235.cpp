#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N;
    string arr[1000];

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    int K = 1;

    while(true)
    {
        map<string, int> m;

        bool flag = true;

        for(int i = 0; i < N; i++)
        {
            string sub_string = arr[i].substr(arr[i].end() - arr[i].begin() - K, K);

            if(m[sub_string])
            {
                K++;

                flag = false;

                break;
            }

            m[sub_string] = 1;
        }

        if(flag)
            break;
    }

    cout << K;

    return 0;
}