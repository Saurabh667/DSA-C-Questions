class Solution {
public:
    int reverseDegree(string s) {
        int out=0;
        for(int i=0;i<s.length();i++){
            int value = 'z' - s[i] + 1;
            out += value * (i + 1);
        }
        return out;

    }
};