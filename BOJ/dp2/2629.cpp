#include <iostream>
#include <cstdlib>

#define SIZE 30

using namespace std;

int N, arr[SIZE];
bool dp_cache[SIZE + 1][SIZE * 500 + 1];

void dp(int index, int weight_side)
{
    if(index > N || dp_cache[index][weight_side])
        return;

    dp_cache[index][weight_side] = true;
    dp(index + 1, weight_side + arr[index]);
    dp(index + 1, weight_side);
    dp(index + 1, abs(weight_side - arr[index]));
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, weights[7];

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    cin >> M;
    for(int i = 0; i < M; i++)
        cin >> weights[i];

    dp(0, 0);

    for(int i = 0; i < M; i++)
        if(weights[i] > SIZE * 500)
            cout << "N ";
        else if(dp_cache[N][weights[i]])
            cout << "Y ";
        else
            cout << "N ";

    return 0;
}