class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length())
            swap(a, b);
        
        int carry = 0;
        int a_length = a.length(), b_length = b.length();
        string answer = "";
        for (int i = 1; i <= a.length(); i++) {
            int digit = 0;

            digit += carry + (a[a_length - i] - '0');
            
            if (i <= b.length())
                digit += b[b_length - i] - '0';
            
            carry = digit >> 1;
            digit %= 2;
            answer += digit + '0';
        }
        
        if (carry)
            answer += carry + '0';
        
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};
