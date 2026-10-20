class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        for(char ch:t){
            mp[ch]--;
        }
        for(auto a:mp){
            if(a.second!=0){
                return false;
            }
        }

        return true;
    }
};