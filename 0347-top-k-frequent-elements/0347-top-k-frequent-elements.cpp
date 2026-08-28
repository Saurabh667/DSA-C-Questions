class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int > mp;
        for(int x:nums){
            mp[x]++;
        }
        vector<int> ans;
        while(k--){
            int maxFreq = 0;
            int maxNum = 0;
            for (auto it : mp) {
                if (it.second > maxFreq) {
                    maxFreq = it.second;
                    maxNum = it.first;
                }
            }
            ans.push_back(maxNum);
            mp.erase(maxNum);
        }

        return ans;

    }
};