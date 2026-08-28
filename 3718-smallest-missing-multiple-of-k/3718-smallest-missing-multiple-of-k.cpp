class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int mul=k;
        while(true){

            bool found=false;
            for(int n:nums){
                if(n==mul){
                    found=true;
                    break;
                }
            }
             if (!found) {
                return mul;
            }

            mul += k;
        }
    }
};