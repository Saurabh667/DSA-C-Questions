class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            map<char,int> mp;
            for(int i=1;i<=9;i++){
            mp['0' + i]=1;
            }
            for(int j=0;j<board[i].size();j++){
                if(board[i][j] !='.'){
                    if(mp[board[i][j]]>0){
                        mp[board[i][j]]--;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        
        for(int j=0;j<board[0].size();j++){
            map<char,int> mp2;
        for(int i=1;i<=9;i++){
            mp2['0' + i]=1;
        }
            for(int i=0;i<board.size();i++){
                if(board[i][j] !='.'){
                    if(mp2[board[i][j]]>0){
                        mp2[board[i][j]]--;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        // Check 3 x 3 boxes
for(int row = 0; row < 9; row += 3) {
    for(int col = 0; col < 9; col += 3) {

        map<char, int> mp3;

        for(int i = row; i < row + 3; i++) {
            for(int j = col; j < col + 3; j++) {

                if(board[i][j] != '.') {

                    if(mp3[board[i][j]] > 0) {
                        return false;
                    }

                    mp3[board[i][j]]++;
                }
            }
        }
    }
}
        return true;;

    }
};