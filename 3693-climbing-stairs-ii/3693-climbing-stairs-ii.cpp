// class Solution {
// public:
//     int climbStairs(int n, vector<int>& costs) {
//         long long cost=0;
//         int i=0;
//         while(i<n ){
//             if(n-i<=3){
//                 int diff=n-i;
//                 cost+=costs[n-1]+((diff)*(diff));
//                 i+=diff;
//             }
//             else if(costs[i]<costs[i+1] && costs[i]<costs[i+2]){
//                 cost+=costs[i]+(1);
//                 i+=1;
//             }
//             else if(costs[i+1]<costs[i] && costs[i+1]<costs[i+2]){
//                 cost+=costs[i+1]+(4);
//                 i+=2;
//             }
//             else{
//                 cost+=costs[i+2]+(9);      
//                 i+=3;          
//             }
//         }
//         return cost;
//     }
// };


class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        vector<int> dp(n+1, INT_MAX);

        dp[0] = 0;

        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= 3; j++) {

                if(i-j >= 0) {

                    dp[i] = min(dp[i],
                        dp[i-j] + costs[i-1] + j*j);
                }
            }
        }

        return dp[n];
    }
};