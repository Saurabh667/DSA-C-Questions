class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int out=0;
        for(int i=0;i<arr1.size();i++){
            bool  flag=true;
            for(int j=0;j<arr2.size();j++){
                int sol=abs(arr1[i]-arr2[j]);
                if(sol<=d){
                    flag=false;
                    break;
                } 
            }
            if(flag){
                out++;
            }
        }
        return out;
    }
};