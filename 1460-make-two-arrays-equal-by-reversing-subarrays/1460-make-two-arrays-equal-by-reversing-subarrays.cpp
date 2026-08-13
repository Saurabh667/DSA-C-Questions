class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int len1=target.size()-1;
        int len2=arr.size()-1;
        if(len1 != len2){
            return false;
        }
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        for(int i=0;i<=len1;i++){
            if(target[i] != arr[i]){
                return false;
            }
        }
        return true;
    }
};