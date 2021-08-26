#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, result;
bool possible = true;
vector<pair<int, int>> v;

void divide_conquer(int length, int width, int height)
{
    if(!length || !width || !height)
        return;

    for(int i = 0; i < n; i++)
    {
        if(v[i].second > 0 && v[i].first <= length && v[i].first <= width && v[i].first <= height)
        {
            v[i].second--;
            result++;
            divide_conquer(length, width, height - v[i].first);
            divide_conquer(length - v[i].first, width, v[i].first);
            divide_conquer(v[i].first, width - v[i].first, v[i].first);

            return;
        }
    }

    possible = false;

    return;
}

int main(void)
{
    ios::sync_with_stdio(0);

    int length, width, height;

    cin >> length >> width >> height >> n;
    for(int i = 0; i < n; i++)
    {
        int temp, number;

        cin >> temp >> number;

        v.push_back({ pow(2, temp), number });
    }

    sort(v.begin(), v.end(), greater<>());

    divide_conquer(length, width, height);

    if(possible)
        cout << result;
    else
        cout << -1;

    return 0;
}