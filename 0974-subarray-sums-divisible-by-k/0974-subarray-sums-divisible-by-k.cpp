// solved 70/76 test cases time limit ecxeed O(n2);

// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         int out=0;
//         for(int i=0;i<nums.size();i++){
//             int sum=0;
//             for(int j=i;j<nums.size();j++){
//                 sum+=nums[j];
//                 if(sum%k==0){
//                     out++;
//                 }
//             }
//         }
//         return out;
//     }
// };

class Solution {
public:
int subarraysDivByK(vector<int>& nums, int k) {
unordered_map<int, int> mp;
mp[0] = 1;

    int sum = 0;
    int out = 0;

    for (int num : nums) {
        sum += num;

        int rem = sum % k;
        if (rem < 0) {
            rem += k;
        }

        if (mp.find(rem) != mp.end()) {
            out += mp[rem];
        }

        mp[rem]++;
    }

    return out;
}


};
