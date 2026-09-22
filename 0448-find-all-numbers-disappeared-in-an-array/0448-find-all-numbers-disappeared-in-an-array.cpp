class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> out;
        map<int,int> mp;
        for(int n:nums){
            mp[n]++;
        }
        for(int i=1;i<nums.size()+1;i++){
            if(mp[i]==0){
                out.push_back(i);
            }
        }
        return out;
    }
};