class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> freq;
        for(int i=0;i<text.length();i++){
            freq[text[i]]++;
        }
        int count=0;
        while(freq['a']>0 && freq['b']>0 &&freq['n']>0 && freq['l']>1 && freq['o']>1){

        if(freq['b']>0 && freq['a']>0 &&freq['n']>0 && freq['l']>1 && freq['o']>1){
            count++;
            freq['a']--;
            freq['b']--;
            freq['n']--;
            freq['l']-=2;
            freq['o']-=2;
            }
        }
        return count;
    }
};