class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1;
        int sum=0;
        int count=0;
        vector<int> out;
        bool present = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                total *= nums[i];   
                sum++;             
            }
            else{
                present = true;
                count++;
            }
        }
        if(count>1){
            for(int i=0;i<nums.size();i++){
                out.push_back(0);
            }
        }
        else{
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (present == true) {
                    out.push_back(0);
                } else {
                    out.push_back(total / nums[i]);
                }
            } else {
                if(sum!=0){
                    out.push_back(total);
                }
                else{
                    out.push_back(0);
                }
            }
        }
        }
        return out;
    }
};