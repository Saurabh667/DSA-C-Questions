class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        vector<int> index;int place=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                // nums.erase(nums.begin()+i);
                index.push_back(i);
                count++;
            }
        }
        for(int i=0;i<index.size();i++){
            nums.erase(nums.begin()+index[i]-place);
            place++;
        }
        for(int i=0;i<count;i++){
            nums.push_back(0);
        }
        return ;
    }
};