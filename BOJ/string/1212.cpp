#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    string octal;
    map<char, string> m;

    cin >> octal;

    m['0'] = "000", m['1'] = "001", m['2'] = "010", m['3'] = "011";
    m['4'] = "100", m['5'] = "101", m['6'] = "110", m['7'] = "111";

    string binary = "";

    for(int i = 0; i < octal.length(); i++)
        binary += m[octal[i]];

    int i = 0;

    while(binary[i] == '0')
        i++;

    binary.erase(0, i);

    if(binary == "")
        cout << '0';
    else
        cout << binary;

    return 0;
}