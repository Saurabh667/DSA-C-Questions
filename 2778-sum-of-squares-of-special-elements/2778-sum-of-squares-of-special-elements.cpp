class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int out=0;
        int len=nums.size();
        for(int i=1;i<=len;i++){
            if(len%i==0){
                out+=nums[i-1]*nums[i-1];
            }
        }
        return out;
    }
};