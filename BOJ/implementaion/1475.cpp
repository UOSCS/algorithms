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
        
    int count[10] = {0, };
    
    string str;
    
    cin >> str;

    for (int i = 0; i < str.length(); i++)
        count[str[i] - '0']++;
    
    count[6] = count[9] = (count[6] + count[9] + 1) >> 1;
    
    int answer = 0;
    for (int i = 0; i < 10; i++)
        answer = max(answer, count[i]);
    
    cout << answer;
    
    return 0;
}

