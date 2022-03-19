//
//  main.cpp
//  cpp
//
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<string, int> m;

void input(int n) {
    
    for (int i = 0; i < n; i++) {
        string name;
        
        cin >> name;
        
        m[name]++;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
    
    int N, M;
    
    cin >> N >> M;
    
    input(N);
    input(M);
    
    vector<string> v;
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
        if ((*it).second >= 2)
            v.push_back((*it).first);
    
    cout << v.size() << '\n';
    for (string str : v)
        cout << str << '\n';
    
    return 0;
}

