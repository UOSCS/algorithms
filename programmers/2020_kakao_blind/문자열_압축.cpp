#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int s_len = s.length();
    int answer = s_len;
    int n = 1;
    
    while (n <= (s_len >> 1)) {
        string prev = s.substr(0, n);
        string tmp = "";
        int count = 0;
        
        for (int i = 0; i < s_len; i += n) {
            string sub_str = s.substr(i, n);

            if (prev == sub_str)
                count++;
            else if (count > 1) {
                tmp += to_string(count);
                tmp += prev;
                prev = sub_str;
                count = 1;
            } else {
                tmp += prev;
                prev = sub_str;
            }
        }
        
        if (count > 1) 
            tmp += to_string(count);
        tmp += prev;
        
        answer = min(answer, (int) tmp.length());
        
        n++;
    }
    
    return answer;
}
