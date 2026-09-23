//  i have passed 49 out of 97 test cases with this

// class Solution {
// public:
//     int step=0;
//     int total=0;
//     void sum(vector<int> nums){
//         for(int i=0;i<nums.size();i++){
//             total+=nums[i];
//         }
//     }
//     int check(vector<int>& nums, int x,int start,int end){
//         if(x==0){
//             return step;
//         }
//         if(total<x){
//             return -1;
//         }
        
//         if(nums[start]>x && nums[end]>x){
//             return -1;
//         }
        
//         if(nums[start]<=x && nums[end]<=x){
//             if(nums[start]>nums[end]){
//                 x=x-nums[start];
//                 start+=1;
//                 step++;
//                 check(nums,x,start,end);
//             }
//             else{
//                 x=x-nums[end];
//                 end-=1;
//                 step++;
//                 check(nums,x,start,end);
//             }
//         }
//         else if(nums[start]<=x && x>nums[end]){
//             x=x-nums[start];
//                 start+=1;
//                 step++;
//                 check(nums,x,start,end);
//         }
//         else{
//             x=x-nums[end];
//             end-=1;
//             step++;
//             check(nums,x,start,end);
//         }
//         return step;
//     }

//     int minOperations(vector<int>& nums, int x) {
//         int start=0;
//         int end=nums.size()-1;
//         // sum(nums);
//         return check(nums,x,start,end);
//     }
// };

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int total = 0;

        for (int num : nums)
            total += num;

        int target = total - x;

        if (target < 0)
            return -1;

        if (target == 0)
            return nums.size();

        int left = 0;
        int sum = 0;
        int maxLen = -1;

        for (int right = 0; right < nums.size(); right++) {

            sum += nums[right];

            while (sum > target) {
                sum -= nums[left];
                left++;
            }

            if (sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        if (maxLen == -1)
            return -1;

        return nums.size() - maxLen;
    }
};