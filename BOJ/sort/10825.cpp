//
//  main.cpp
//  cpp
//
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool my_cmp(tuple<string, int, int, int> &t1, tuple<string, int, int, int> &t2) {
    if (get<1>(t1) == get<1>(t2)) {
        if (get<2>(t1) == get<2>(t2))
            if (get<3>(t1) == get<3>(t2))
                return get<0>(t1) < get<0>(t2);
            else
                return get<3>(t1) > get<3>(t2);
        else
            return get<2>(t1) < get<2>(t2);
    }
    else
        return get<1>(t1) > get<1>(t2);
}

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);
    
    int N;
    vector<tuple<string, int, int, int>> v;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        string name;
        int kor, math, eng;
        
        cin >> name >> kor >> eng >> math;
        
        v.push_back({name, kor, eng, math});
    }
    
    sort(v.begin(), v.end(), my_cmp);
    
    for (int i = 0; i < N; i++)
        cout << get<0>(v[i]) << '\n';
    
    return 0;
}

