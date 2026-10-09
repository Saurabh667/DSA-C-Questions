// unable to solve "(()))(()))()())))" but the rest is ok ;

// class Solution {
// public:
//     int minInsertions(string s) {
//         stack<char> st;
//         for (char c : s) {
//             if (st.empty()) {
//                 st.push(c);
//             } else if (c == ')' && st.top() == ')') {
//                 st.pop();
//                 if (!st.empty()) {
//                     if (st.top() == '(') {
//                         st.pop();
//                     } else {
//                         st.push(')');
//                         st.push(c);
//                     }
//                 } else {
//                     st.push(')');
//                     st.push(c);
//                 }
//             } else {
//                 st.push(c);
//             }
//         }
//         int ans = 0;
//         int right = 0;
//         while (!st.empty()) {
//             if (st.top() == ')') {
//                 st.pop();
//                 if (!st.empty()) {
//                     if (st.top() == '(') {
//                         st.pop();
//                         ans++;
//                     } else {
//                         right++;
//                     }
//                 }
//                 else{
//                     right++;
//                 }
//             } else if (st.top() == '(') {
//                 st.pop();
//                 ans += 2;
//             }
//         }
//         if(right%2==0){
//             return ans + right/2;
//         }
//         else{
//             right=right-1;
//             return ans+right/2+2;
//         }
//         return ans+right/2;
//     }
// };


class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int need = 0;

        for (char c : s) {
            if (c == '(') {
                if (need % 2 == 1) {
                    ans++;
                    need--;
                }

                need += 2;
            }
            else {
                need--;

                if (need < 0) {
                    ans++;
                    need = 1;
                }
            }
        }

        return ans + need;
    }
};