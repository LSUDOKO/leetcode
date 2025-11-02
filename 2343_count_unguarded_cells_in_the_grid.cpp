class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (auto& w : walls) {
            int row = w[0];
            int col = w[1];
            grid[row][col] = 1;
        }

        for (auto& g : guards) {
            int row = g[0];
            int col = g[1];
            grid[row][col] = 2;
        }

        for (int i = 0; i < m; i++) {
            bool active = false;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    active = false;
                } 
                else if (grid[i][j] == 2) {
                    active = true;
                } 
                else {
                    if (active) {
                        grid[i][j] = 3;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            bool active = false;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    active = false;
                } 
                else if (grid[i][j] == 2) {
                    active = true;
                } 
                else {
                    if (active) {
                        grid[i][j] = 3;
                    }
                }
            }
        }

        for (int j = 0; j < n; j++) {
            bool active = false;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 1) {
                    active = false;
                } 
                else if (grid[i][j] == 2) {
                    active = true;
                } 
                else {
                    if (active) {
                        grid[i][j] = 3;
                    }
                }
            }
        }

        for (int j = 0; j < n; j++) {
            bool active = false;
            for (int i = m - 1; i >= 0; i--) {
                if (grid[i][j] == 1) {
                    active = false;
                } 
                else if (grid[i][j] == 2) {
                    active = true;
                } 
                else {
                    if (active) {
                        grid[i][j] = 3;
                    }
                }
            }
        }

        int unguarded = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unguarded++;
                }
            }
        }

        return unguarded;
    }
};