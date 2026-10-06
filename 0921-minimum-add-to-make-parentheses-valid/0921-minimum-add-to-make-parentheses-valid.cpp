class Solution {
public:
    
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count=0;
        for(char c:s){
            if(st.empty()){
                st.push(c);
            }
            else if(c==')' && st.top()=='('){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        while(!st.empty()){
            st.pop();
            count++;
        }
        return count;
    }
};