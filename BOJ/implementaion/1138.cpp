#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, arr[10];
    vector<int> line;

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    for(int i = N - 1; i >= 0; i--)
        line.insert(line.begin() + arr[i], i + 1);
    
    for(int i : line)
        cout << i << ' ';

    return 0;
}