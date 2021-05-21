#include <iostream>
#include <vector>

using namespace std;

int pre_arr[1000], in_arr[1000], root_index[1001];

void post_order(int pre_left, int pre_right, int in_left, int in_right)
{
    if(pre_left > pre_right || in_left > in_right)
        return;
    int root = pre_arr[pre_left];
    int mid = root_index[root];
    int bias = mid - in_left;
    post_order(pre_left + 1, pre_left + bias, in_left, mid - 1);
    post_order(pre_left + bias + 1, pre_right, mid + 1, in_right);
    cout << root << ' ';
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;

    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        for(int j = 0; j < n; j++)
            cin >> pre_arr[j];
        for(int j = 0; j < n; j++)
        {
            cin >> in_arr[j];
            root_index[in_arr[j]] = j;
        }
        post_order(0, n - 1, 0, n - 1);
        cout << '\n';
    }

    return 0;
}