class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char, int> um;
        char prev = s[0];
        int answer = 0;

        um['I'] = 1, um['V'] = 5, um['X'] = 10, um['L'] = 50;
        um['C'] = 100, um['D'] = 500, um['M'] = 1000;

        for (int i = 1; i <= s.length(); i++) {
            if (i == s.length() || s[i] == 'I') {
                answer += um[prev];
            } else {
                if ((s[i] == 'V' || s[i] == 'X') && prev == 'I') {
                    answer += -1;
                } else if ((s[i] == 'L' || s[i] == 'C') && prev == 'X') {
                    answer += -10;
                } else if ((s[i] == 'D' || s[i] == 'M') && prev == 'C') {
                    answer += -100;
                } else {
                    answer += um[prev];
                }
            }

            prev = s[i];
        }

        return answer;
    }
};
