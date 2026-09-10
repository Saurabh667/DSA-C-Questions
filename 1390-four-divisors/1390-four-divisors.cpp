// class Solution {
//     int out=0;
// private:
//     void sDivisor(int num){
//         vector<int> divisor;
//         for(int i=1;i<=num/2;i++){
//             if(num%i==0){
//                 divisor.push_back(i);
//             }
//         }
//         if(divisor.size()==3){
//             for(int i=0;i<divisor.size();i++){
//                 out+=divisor[i];
//             }
//             out+=num;
//         }
//     }
// public:
//     int sumFourDivisors(vector<int>& nums) {

//         for(int i=0;i<nums.size();i++){
//             sDivisor(nums[i]);
//         }
//         return out;
//     }
// };



class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

        int ans = 0;

        for (int num : nums) {

            int count = 0;
            int sum = 0;

            for (int i = 1; i * i <= num; i++) {

                if (num % i == 0) {

                    int j = num / i;

                    count++;
                    sum += i;

                    if (i != j) {
                        count++;
                        sum += j;
                    }

                    // More than 4 divisors
                    if (count > 4)
                        break;
                }
            }

            if (count == 4)
                ans += sum;
        }

        return ans;
    }
};