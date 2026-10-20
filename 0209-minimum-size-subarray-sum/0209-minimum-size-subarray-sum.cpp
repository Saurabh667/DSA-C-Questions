// solved 18/23 test cases with my own method ....

// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int out = INT_MAX;
//         for (int i = 0; i < nums.size(); i++) {
//             int sum = 0;
//             int count=0;
//             for (int j = i; j < nums.size(); j++) {
//                 sum += nums[j];
//                 count++;
//                 if (sum >= target) {
//                     out = min(count, out);
//                 }
//             }
//         }
//         // return out;
//         return out == INT_MAX ? 0 : out;
//     }
// };

class Solution {
public:
int minSubArrayLen(int target, vector<int>& nums) {
int left = 0;
int sum = 0;
int out = INT_MAX;

    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];

        while (sum >= target) {
            out = min(out, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    return out == INT_MAX ? 0 : out;
}


};
