#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    while(!cin.eof())
    {
        pair<double, double> a, b, c, d, answer;

        cin >> a.first >> a.second;
        cin >> b.first >> b.second;
        cin >> c.first >> c.second;
        cin >> d.first >> d.second;

        pair<double, double> inter_point;

        if(a.first == c.first && a.second == c.second)
        {   
            d.first = b.first + d.first - a.first;
            d.second = b.second + d.second - a.second;
        }
        else if(a.first == d.first && a.second == d.second)
        {
            d.first = b.first + c.first - a.first;
            d.second = b.second + c.second - a.second;
        }
        else if(b.first == c.first && b.second == c.second)
        {
            d.first = a.first + d.first - b.first;
            d.second = a.second + d.second - b.second;
        }
        else
        {
            d.first = a.first + c.first - b.first;
            d.second = a.second + c.second - b.second;
        }

        cout << fixed;
        cout.precision(3);
        cout << d.first << ' ';
        cout << d.second << '\n';
    }

    return 0;
}