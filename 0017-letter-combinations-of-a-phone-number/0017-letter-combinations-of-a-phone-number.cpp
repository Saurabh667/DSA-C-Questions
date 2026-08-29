class Solution {
private:
    void solve(string digit,string output,int index,vector<string>& ans,string letter[]){
        if(index>=digit.size()){
            ans.push_back(output);
            return;
        }
        int number=digit[index]-'0';
        string value=letter[number];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digit,output,index+1,ans,letter);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()<=0){
            return ans;
        }
        string output;
        int index=0;
        string letter[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,index,ans,letter);
        return ans;
    }
};