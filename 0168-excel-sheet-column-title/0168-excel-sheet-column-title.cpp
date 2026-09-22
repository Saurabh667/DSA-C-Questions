class Solution {
public:
    string convertToTitle(int columnNumber) {
        string out;
        map<int,char> mp;
        for(int i=1;i<=26;i++){
            mp[i]='A'+i-1;
        }
        while(columnNumber>0){
            columnNumber--;
            int digit = columnNumber % 26;
            out.push_back(mp[digit+1]);
            columnNumber /= 26;
            // columnNumber=columnNumber/26;
        }
        reverse(out.begin(),out.end());
        return out;
    }
};