class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        bool answer = true;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else if (st.empty()) {
                answer = false;

                break;
            } else {

                char c = st.top();

                st.pop();

                if ((c == '(' && s[i] != ')') || (c == '{' && s[i] != '}') || c == '[' && s[i] != ']') {
                    answer = false;

                    break;
                }
            }
        }

        return answer && st.empty();
    }
};
