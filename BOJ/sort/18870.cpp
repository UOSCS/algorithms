#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N;
    vector<int> arr;

    cin >> N;

    arr.resize(N);

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    vector<int> copy_arr(arr);

    sort(copy_arr.begin(), copy_arr.end());

    copy_arr.erase(unique(copy_arr.begin(), copy_arr.end()), copy_arr.end());

    for(int i = 0; i < N; i++)
    {
        vector<int>::iterator it = lower_bound(copy_arr.begin(), copy_arr.end(), arr[i]);

        cout << it - copy_arr.begin() << ' ';
    }

    return 0;
}