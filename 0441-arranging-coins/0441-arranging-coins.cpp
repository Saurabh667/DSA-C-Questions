class Solution {
public:
    int arrangeCoins(int n) {
        int steps=0;
        int cap=1;
        while(cap<=n){
            n=n-cap;
            steps++;
            cap++;
        }
        return steps;
    }
};