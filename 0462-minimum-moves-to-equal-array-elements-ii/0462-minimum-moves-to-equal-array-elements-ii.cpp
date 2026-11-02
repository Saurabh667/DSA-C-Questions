class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        int move=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=median){
                move+=nums[i]-median;
            }
            else{
                move+=median-nums[i];
            }
        }
        return move;
    }
};