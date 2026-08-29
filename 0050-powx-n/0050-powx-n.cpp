// my solution passed 303 test case out of 307

// class Solution {
// public:
//     double myPow(double x, int n) {
//         if(n==1){
//             return x;
//         }
//         else if(n==0){
//             return 1;
//         }
//         double output=1;
//         if(n>=1){
//             long long step=n;
//             while(step!=0){
//                 output=output*x;
//                 step--;
//             }
//         }
//         else{
//             double num=1;
//             long long step=-n;
//             while(step!=0){
//                 num=num*x;
//                 step--;
//             }
//             output=1/num;
//         }
//         return output;
//     }
// };


class Solution {
public:

    double power(double x, long long n) {

        if(n == 0)
            return 1;

        double half = power(x, n / 2);

        if(n % 2 == 0)
            return half * half;

        return half * half * x;
    }

    double myPow(double x, int n) {

        long long num = n;

        if(num < 0) {
            return 1 / power(x, -num);
        }

        return power(x, num);
    }
};