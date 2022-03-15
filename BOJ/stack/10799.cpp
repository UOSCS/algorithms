//
//  main.cpp
//  cpp
//
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
        
    string str;
    
    cin >> str;
    
    bool flag = false;
    int n_left = 0, answer = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            n_left++;
            flag = true;
        } else if (flag) {
            answer += --n_left;
            flag = false;
        } else {
            answer++;
            n_left--;
        }
    }
    
    cout << answer;
    
    return 0;
}

