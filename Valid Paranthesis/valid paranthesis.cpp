class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (isOpening(ch)) {
                st.push(ch);
            }
            else {
                if (st.size() == 0) {
                    return false;
                }
                else {
                    char och = st.top();
                    st.pop();
                    if (!isMatching(och, ch)) return false;
                }
            }
        }
        
        if (st.size() > 0) {
            return false;
        }
        
        return true;
    }
    
    bool isOpening(char ch) {
        return (ch == '(' || ch == '{' || ch == '[');
    }
    
    bool isMatching(char och, char cch) {
        return (och == '(' && cch == ')') || (och == '[' && cch == ']') || (och == '{' && cch == '}');
    }
};