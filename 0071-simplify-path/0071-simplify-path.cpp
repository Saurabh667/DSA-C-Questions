// class Solution {
// public:
//     string simplifyPath(string path) {
//         // int size=path.size()-1;
//         // stack<char> st;
//         // int top=-1;
//         // int i=0;
//         // string rev="";

//         // string out="";
//         // while(i<=size){

//         //     if(i==0){
//         //         top++;
//         //         st.push(path[i]);
//         //         // i++;
//         //     }
//         //     if(path[i]=='.'){
//         //         if(st.top()=='.'){
//         //             st.pop();
//         //             top--;
//         //             st.pop();
//         //             top--;
//         //             for(int j=i;j>=0;j--){
//         //                 if(st.top()!='/'){
//         //                     st.pop();
//         //                     top--;
//         //                 }
//         //                 else{
//         //                     break;
//         //                 }
//         //             }
//         //         }
//         //     }
//         //     if(path[i] != st.top()){
//         //         top++;
//         //         st.push(path[i]);
//         //     }
//         //     else if(path[i] == '/' && st.top() == path[i]){
//         //         top--;
//         //     }

//         //     i++;
//         // }
//         // if(st.top()=='/'){
//         //     st.pop();
//         // }
//         // while(top>=0){
//         //     rev.push_back(st.top());
//         //     top--;
//         // }
//         // int s2=rev.size()-1;
//         // for(int k=0;k<=s2;k++){
//         //     out.push_back(rev[k]);
//         // }
//         // return out;
//         stack<char> st;
//         for (int i = 0; i < path.size(); i++) {
//             if (path[i] == '/') {
//                 if (st.empty() || st.top() != '/') {
//                     st.push('/');
//                 }

//                 continue;
//             }
//             if (path[i] == '.') {
//                 if (i + 1 < path.size() && path[i + 1] == '.') {
//                     if (i + 2 == path.size() || path[i + 2] == '/') {

//                         i += 2;

//                         while (!st.empty() && st.top() != '/') {
//                             st.pop();
//                         }

//                         if(!st.empty() && st.top() == '/') {
//                             st.pop();
//                         }

//                         if (i < path.size() && path[i] == '/') {
//                             i--;
//                         }

//                         continue;
//                     }
//                 }

//                 if (i + 1 == path.size() || path[i + 1] == '/') {
//                     continue;
//                 }
//             }

//             st.push(path[i]);
//         }
//         if (!st.empty() && st.top() == '/' && st.size() > 1) {
//             st.pop();
//         }

//         string result = "";

//         while (!st.empty()) {
//             result.push_back(st.top());
//             st.pop();
//         }

//         reverse(result.begin(), result.end());

//         if (result.empty()) {
//             return "/";
//         }

//         return result;
//     }
// };

class Solution {
public:
    string simplifyPath(string path) {

        stack<char> st;

        for (int i = 0; i < path.size(); i++) {

            // Handle '/'
            if (path[i] == '/') {

                if (st.empty() || st.top() != '/') {
                    st.push('/');
                }

                continue;
            }

            // Handle dots only if they START a path component
            if (path[i] == '.' && (i == 0 || path[i - 1] == '/')) {

                int j = i;

                // Count consecutive dots
                while (j < path.size() && path[j] == '.') {
                    j++;
                }

                int dots = j - i;

                // Exactly "."
                if (dots == 1 &&
                    (j == path.size() || path[j] == '/')) {

                    i = j - 1;
                    continue;
                }

                // Exactly ".."
                if (dots == 2 &&
                    (j == path.size() || path[j] == '/')) {

                    // Remove '/' after previous directory
                    if (!st.empty() && st.top() == '/') {
                        st.pop();
                    }

                    // Remove previous directory
                    while (!st.empty() && st.top() != '/') {
                        st.pop();
                    }

                    i = j - 1;
                    continue;
                }

                // "...", "....", etc.
                // Normal directory name
                while (i < j) {
                    st.push(path[i]);
                    i++;
                }

                i--;
                continue;
            }

            // Normal character
            st.push(path[i]);
        }

        // Remove trailing '/'
        if (!st.empty() && st.top() == '/' && st.size() > 1) {
            st.pop();
        }

        // Convert stack to string
        string result = "";

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        if (result.empty()) {
            return "/";
        }

        return result;
    }
};