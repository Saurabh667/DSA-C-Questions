class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minPrice){
                minPrice=prices[i];
            }
            // minPrice=Math.min(minPrice,prices[i]);
            int currP=prices[i]-minPrice;
        if(currP>maxProfit){
            maxProfit=currP;
        }
            // maxProfit=Math.max(maxProfit,prices[i]-minOrice);
        }
        return maxProfit;
    }
};