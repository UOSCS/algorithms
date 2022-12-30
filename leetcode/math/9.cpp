class Solution {
public:

    bool _isPalindrome(string s, int i) {

        if (i < 0)
            return true;

        int j = s.length() - i - 1;

        return (s[i] == s[j]) ? _isPalindrome(s, i - 1) : false;
    }

    bool isPalindrome(int x) {

        if (x < 0)
            return false;
        if (!x)
            return true;
        
        string s = to_string(x);

        return _isPalindrome(s, s.size() >> 1);
    }
};
