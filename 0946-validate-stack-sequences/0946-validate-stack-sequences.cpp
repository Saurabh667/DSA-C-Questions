class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int s1 = pushed.size() - 1;
        int s2 = popped.size() - 1;
        int i1 = 0;
        int i2 = 0;
        stack<int> st;
        while (i1 <= s1) {
            st.push(pushed[i1]);
            i1++;

            while (!st.empty() && i2 <= s2 && st.top() == popped[i2]) {
                st.pop();
                i2++;
            }
        }
        return st.empty();
    }
};