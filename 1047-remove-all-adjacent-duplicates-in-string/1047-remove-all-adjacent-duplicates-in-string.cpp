class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string out;
        for(char c:s){
            if(st.empty()){
                st.push(c);
            }
            else{
                if(st.top()==c){
                    st.pop();
                }
                else{
                    st.push(c);
                }
            }
        }
        while(!st.empty()){
            out.push_back(st.top());
            st.pop();
        }
        reverse(out.begin(),out.end());
        return out;
    }
};