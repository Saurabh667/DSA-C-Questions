class Solution {
public:
    string removeStars(string s) {
        string out;
        for(char ch:s){
            if(ch=='*'){
                out.pop_back();

            }
            else{
                out+=ch;
            }
        }
        return out;
    }
};