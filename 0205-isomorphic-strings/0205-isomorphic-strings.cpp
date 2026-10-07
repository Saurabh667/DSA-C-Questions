// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         map<char, int> mp1;
//         map<char, int> mp2;
//         for (char c : s) {
//             mp1[c]++;
//         }
//         for (char c : t) {
//             mp2[c]++;
//         }

//         vector<char> alp;
//         for (auto [ch, freq] : mp1) {
//             if (freq > 0) {
//                 alp.push_back(ch);
//             }
//         }
//         for (int i = 0; i < alp.size(); i++) {
//             int freqA = mp1[alp[i]];
//             bool found=false;
//             for (auto it : mp2) {
//                 if (it.second == freqA) {
//                     mp2[it.first]=0;
//                     found=true;
//                     break;
//                 }
//             }
//             if(found==false){
//                 return false;
//             }
//         }
//         return true;
//     }
// };



class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp1;
        map<char, char> mp2;

        for (int i = 0; i < s.length(); i++) {
            char a = s[i];
            char b = t[i];

            if (mp1.count(a) && mp1[a] != b)
                return false;

            if (mp2.count(b) && mp2[b] != a)
                return false;

            mp1[a] = b;
            mp2[b] = a;
        }

        return true;
    }
};


