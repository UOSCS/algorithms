//
//  main.cpp
//  cpp
//
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    ios::sync_with_stdio(0);

    vector<string> dict, puzzle;
    
    while (true) {
        string tmp;
        cin >> tmp;
        if (tmp == "-")
            break;
        dict.push_back(tmp);
    }
    
    while (true) {
        string tmp;
        cin >> tmp;
        if (tmp == "#")
            break;
        puzzle.push_back(tmp);
    }
    
    for (int i = 0; i < puzzle.size(); i++) {
        
        int n_alphabet[26] = {0};
        int min_count = 200000, max_count = 0;
        vector<char> min_char, max_char;
        
        for (int j = 0; j < puzzle[i].size(); j++)
            n_alphabet[puzzle[i][j] - 'A']++;
        
        for (int j = 0; j < puzzle[i].size(); j++) {
            int count = 0;
            for (int k = 0; k < dict.size(); k++) {
                if (dict[k].find(puzzle[i][j]) != string::npos) {
                    int tmp_n_alphabet[26];
                    memcpy(tmp_n_alphabet, n_alphabet, sizeof(n_alphabet));
                    bool flag = true;
                    for (int l = 0; l < dict[k].size(); l++) {
                        if (--tmp_n_alphabet[dict[k][l] - 'A'] < 0) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                        count++;
                }
            }
            
            if (count < min_count) {
                min_count = count;
                min_char.clear();
                min_char.push_back(puzzle[i][j]);
            } else if (count == min_count)
                min_char.push_back(puzzle[i][j]);
            if (count > max_count) {
                max_count = count;
                max_char.clear();
                max_char.push_back(puzzle[i][j]);
            } else if (count == max_count)
                max_char.push_back(puzzle[i][j]);
        }
        
        sort(min_char.begin(), min_char.end());
        min_char.erase(unique(min_char.begin(),min_char.end()), min_char.end());
        sort(max_char.begin(), max_char.end());
        max_char.erase(unique(max_char.begin(),max_char.end()), max_char.end());
        for (char c : min_char)
            cout << c;
        cout << ' ' << min_count << ' ';
        for (char c : max_char)
            cout << c;
        cout << ' ' << max_count << '\n';
    }
    
    return 0;
}

