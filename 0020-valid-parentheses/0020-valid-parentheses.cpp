class Solution {
public:
    bool isValid(string s) {
        int size=s.size()-1;
        stack<char> st;
        int top=-1;
        int i=0;
        while(i<=size){
            if(s[i]=='(' || s[i]=='{'||s[i]=='['){
                top++;
                st.push(s[i]);
                i++;
            }
            else{
                if (st.empty()) {
                    return false;
                }
                if (s[i] == ')' && st.top() != '(') {
                    return false;
                }

                if (s[i] == '}' && st.top() != '{') {
                    return false;
                }

                if (s[i] == ']' && st.top() != '[') {
                    return false;
                }

                st.pop();
                i++;
            }
        }
        return st.empty();
    }
};