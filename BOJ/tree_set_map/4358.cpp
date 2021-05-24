#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    map<string, double> m;
    char str[31];
    int n = 0;

    while(cin.getline(str, 31))
    {
        n++;
        m[str] += 1.0;
    }

    cout << fixed;
    cout.precision(4);
    for(pair<string, double> p : m)
        cout << p.first << ' ' << p.second / n * 100 << '\n';
    
    return 0;
}