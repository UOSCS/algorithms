#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, M;
    vector<int> package, each;

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int package_price, each_price;

        cin >> package_price >> each_price;

        package.push_back(package_price), each.push_back(each_price);
    }

    sort(package.begin(), package.end());
    sort(each.begin(), each.end());

    if(each[0] * 6 <= package[0])
        cout << N * each[0];
    else
        if(((N / 6) + 1) * package[0] < (N / 6) * package[0] + (N % 6) * each[0])
            cout << ((N / 6) + 1) * package[0];
        else
            cout << (N / 6) * package[0] + (N % 6) * each[0];

    return 0;
}