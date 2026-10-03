// i have passed 146 out of 235 test cases 
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int longest = 0;
//         if (s.length() == 0) {
//             return 0;
//         }
//         int curr = 0;
//         stack<char> st;
//         for (char c : s) {
//             if(st.empty()){
//                 st.push(c);
//             }
//             else if (c == ')' && st.top() == '(') {
//                 curr += 1;
//                 st.pop();
//             } 
//             else if (c == ')' && st.top() == ')') {
//                 if (longest <= curr) {
//                     longest = curr;
//                 } else {
//                     curr = 0;
//                 }
//                 curr=0;
//             } 
//             else {
//                 st.push(c);
//             }
//         }
//         // if(!st.empty()){
//         //     longest--;
//         // }
//         // longest=curr;
//         if (longest <= curr) {
//             longest = curr;
//         }
//         return longest*2;
//     }
// };


class Solution {
public:
    int longestValidParentheses(string s) {
        int longest = 0;
        stack<int> st;
        st.push(-1);                 // base: index before the string start

        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);      // unmatched ')': new base
                } else {
                    longest = max(longest, i - st.top());
                }
            }
        }
        return longest;
    }
};