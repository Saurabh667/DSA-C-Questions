class Solution {
private:
    char check(string s, string t){
        string out=s;
        int len1=s.size()-1;
        int len2=t.size()-1;
        for(int i=0;i<=len2;i++){
            out.erase(out.find(t[i]), 1);
        }
        return out[0];
    }
public:
    char findTheDifference(string s, string t) {
        if(s==""){
            return t[0];
        }
        if(t==""){
            return s[0];
        }
        
        int len1=s.size()-1;
        int len2=t.size()-1;
        if(len1>=len2){
            return check(s,t);
        }
        else{
            return check(t,s);
        }
    }
};