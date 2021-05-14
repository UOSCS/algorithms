#include <iostream>

using namespace std;

int in_arr[100000], post_arr[100000], root_index[100001];

void pre_order(int in_left, int in_right, int post_left, int post_right)
{
    if(in_left > in_right || post_left > post_right)
        return;
    int root = post_arr[post_right];
    int mid = root_index[root];
    int bias = mid - in_left;
    cout << root << ' ';
    pre_order(in_left, mid - 1, post_left, post_left + bias - 1);
    pre_order(mid + 1, in_right, post_left + bias, post_right - 1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> in_arr[i];
        root_index[in_arr[i]] = i;
    }
    for(int i = 0; i < n; i++)
        cin >> post_arr[i];

    pre_order(0, n - 1, 0, n - 1);

    return 0;
}