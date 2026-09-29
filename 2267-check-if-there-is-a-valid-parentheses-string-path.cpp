class Solution {
public:
    int m, n;
    bool t[101][101][201];
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if ((m+n-1)%2 == 1)
            return false;
        if (grid[0][0] != '(' || grid[m-1][n-1] != ')') {
            return false;
        }
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                for (int openCount = 0; openCount <= i+j+1; openCount++) {
                    if (i == m-1 && j == n-1) {
                        t[i][j][openCount] = (openCount == 0);
                        continue;
                    }
                    t[i][j][openCount] = false;
                    if (i+1 < m) {
                        int nextOpenCount = openCount + (grid[i+1][j] == '(' ? 1 : -1);
                        if (nextOpenCount >= 0 && t[i+1][j][nextOpenCount])
                            t[i][j][openCount] = true;
                    }
                    if (j+1 < n) {
                        int nextOpenCount = openCount + (grid[i][j+1] == '(' ? 1 : -1);
                        if (nextOpenCount >= 0 && t[i][j+1][nextOpenCount])
                            t[i][j][openCount] = true;
                    }
                }
            }
        }
        return t[0][0][1];
    }
};