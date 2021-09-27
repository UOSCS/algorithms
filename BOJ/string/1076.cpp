#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    map<string, int> value, multiply;

    value["black"] = 0, multiply["black"] = 1;
    value["brown"] = 1, multiply["brown"] = 10;
    value["red"] = 2, multiply["red"] = 100;
    value["orange"] = 3, multiply["orange"] = 1000;
    value["yellow"] = 4, multiply["yellow"] = 10000;
    value["green"] = 5, multiply["green"] = 100000;
    value["blue"] = 6, multiply["blue"] = 1000000;
    value["violet"] = 7, multiply["violet"] = 10000000;
    value["grey"] = 8, multiply["grey"] = 100000000;
    value["white"] = 9, multiply["white"] = 1000000000;

    string a, b, c;

    cin >> a >> b >> c;

    string answer = to_string(value[a]) + to_string(value[b]);

    cout << stoll(answer) * (long long) multiply[c];

    return 0;
}