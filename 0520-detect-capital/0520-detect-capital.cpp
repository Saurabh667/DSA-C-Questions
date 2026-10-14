class Solution {
public:
    bool detectCapitalUse(string word) {
        bool ans=true;
        int count=0;
        int len=word.length();
        bool first=false;
        if(word[0]<97){
                first=true;
            }
        for(int i=0;i<word.length();i++){
            if(word[i]<97){
                count++;
            }
            
        }
        if(first==true){
            if(count==1){
                count=0;
            }
        }
        if(count==0 || count==len){
            return true;
        }
        else{
            return false;
        }
        return true;
    }
};