class Solution {
public:
    bool isPal(string s,int start,int end){
        while(start<end){
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int start=0;
        int end=s.length()-1;
        while(start<end){
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                return isPal(s,start+1,end) || isPal(s,start,end-1);
            }
        }
        return true;
    }
};