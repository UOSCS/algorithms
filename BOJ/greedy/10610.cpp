//
//  main.cpp
//  cpp
//
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
    
    string str;
    
    cin >> str;
    
    bool flag = false;
    int sum = 0;
    
    for (int i = 0; i < str.length(); i++) {
        sum += str[i] - '0';
        if (str[i] == '0')
            flag = true;
    }
    
    if (!flag || (sum % 3))
        cout << -1;
    else {
        sort(str.begin(), str.end(), greater<>());
        for (char c : str)
            cout << c;
    }
    
    return 0;
}

