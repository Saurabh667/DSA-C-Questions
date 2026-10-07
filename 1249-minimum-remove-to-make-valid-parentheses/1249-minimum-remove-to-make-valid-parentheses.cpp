class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // stack<char,int> st;
        stack<pair<char, int>> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' && st.empty()){
                st.push({s[i],i});
            }
            else if(s[i]==')' && st.empty()){
                st.push({s[i],i});
            }
            else if(s[i]==')' && st.top().first=='('){
                st.pop();
            }
            else if(s[i]=='(' || s[i]==')'){
                st.push({s[i],i});
            }
        }
        if(st.empty()){
            return s;
        }
        while(!st.empty()){
            int p=st.top().second;
            s.erase(p,1);
            st.pop();
        }
        return s;
    }
};