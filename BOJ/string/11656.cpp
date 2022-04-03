//
//  main.cpp
//  cpp
//
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
    
    string str;
    
    cin >> str;
    
    vector<string> v;
    
    for (int i = 0; i < str.length(); i++) {
        string sub_str;
        
        sub_str = str.substr(i);
        
        v.push_back(sub_str);
    }
    
    sort(v.begin(), v.end());
    
    for (string s : v)
        cout << s << '\n';
    
    return 0;
}

