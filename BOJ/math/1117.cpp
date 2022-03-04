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
    
    long long W, H, f, c, x1, y1, x2, y2;
    
    cin >> W >> H >> f >> c >> x1 >> y1 >> x2 >> y2;
    
    long long dup;
    
    dup = min(f, W - f);
    
    long long row;
    
    if (x2 <= dup)
        row = (x2 - x1) << 1;
    else if (x1 < dup)
        row = (x2 - dup) + ((dup - x1) << 1);
    else
        row = x2 - x1;
    
    cout << (W * H) - ((c + 1) * (y2 - y1) * row);
    
    return 0;
}

