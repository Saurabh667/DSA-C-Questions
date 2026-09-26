// I have passed 98/105 test cases with this method but got time limit exceed
// error

// class Solution {
// public:
//     stack<char> q;
//     void insert(vector<vector<string>>& knowledge){
//        string name;
//        q.pop();
//        while(q.top()!='('){
//             name.push_back(q.top());
//             q.pop();
//        } ;
//        q.pop();
//        reverse(name.begin(), name.end());
//        bool check=false;
//     for(int i=0;i<knowledge.size();i++){
//         if(knowledge[i][0]==name){
//             check=true;
//             for(char c:knowledge[i][1]){
//             q.push(c);
//             }
//             return;
//         }
//     }
//     if(check==false){
//         q.push('?');
//     }
//     return;
//     }
//     string evaluate(string s, vector<vector<string>>& knowledge) {
//         string out;
//         for(char c:s){
//             q.push(c);
//             if(c==')'){
//                 insert(knowledge);
//             }
//         }
//         while(!q.empty()){
//             out.push_back(q.top());
//             q.pop();
//         }
//         reverse(out.begin(),out.end());
//         return out;
//     }
// };

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string, string> mp;
        for (auto x : knowledge) {
            mp[x[0]] = x[1];
        }
        string out;
        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {

                string name = "";

                i++;

                while (s[i] != ')') {
                    name += s[i];
                    i++;
                }

                if (mp.find(name) != mp.end()) {
                    out += mp[name];
                } else {
                    out += '?';
                }

            } else {
                out += s[i];
            }
        }
        return out;
    }
};
