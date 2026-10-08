class Solution {
public:
    int ans = 0;
    bool isSafe(int newx, int newy, vector<vector<bool>>& visited,
                vector<vector<int>>& grid, int row, int col) {
        if ((newx < row && newx >= 0) && (newy < col && newy >= 0) &&
            (grid[newx][newy] != -1) && (visited[newx][newy] != 1)) {
            return true;
        } else {
            return false;
        }
    }
    void solve(int x, int y, vector<vector<int>>& grid, int row, int col,
               vector<vector<bool>>& visited, int count, int total, int endx,
               int endy) {
        if (x == endx && y == endy) {
            if (count == total)
                ans++;

            return;
        }

        // down
        visited[x][y] = 1;
        if (isSafe(x + 1, y, visited, grid, row, col)) {
            solve(x + 1, y, grid, row, col, visited, count + 1, total, endx,endy);
        }
        // left
        if (isSafe(x, y - 1, visited, grid, row, col)) {

            solve(x, y - 1, grid, row, col, visited, count + 1, total, endx,endy);
        }
        // right
        if (isSafe(x, y + 1, visited, grid, row, col)) {

            solve(x, y + 1, grid, row, col, visited, count + 1, total, endx,endy);
        }
        // up
        if (isSafe(x - 1, y, visited, grid, row, col)) {

            solve(x - 1, y, grid, row, col, visited, count + 1, total, endx,endy);
        }
        visited[x][y] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, 0));
        int total = 0;
        int startX, startY;
        int endx, endy;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] != -1) {
                    total++;
                }
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }

                if (grid[i][j] == 2) {
                    endx = i;
                    endy = j;
                }
            }
        }
            solve(startX, startY, grid, row, col, visited, 1, total, endx, endy);
            return ans;
        }
    };