class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> out;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto n:mp){
            if(n.second>1){
                out.push_back(n.first);
            }
        }
        return out;
    }
};