class Solution {
    void dfs(vector<vector<int>>&grid,int row, int col){
        grid[row][col]=0;
        int pr[]={-1,1,0,0};
        int pc[]={0,0,-1,1};
        for (int i=0;i<4;i++){
            int fr=row+pr[i];
            int fc=col+pc[i];
            if (fr>=0 && fr<grid.size() && fc>=0 && fc<grid[0].size()){
                if (grid[fr][fc]==1){
                    grid[fr][fc]=0;
                    dfs(grid,fr,fc);
                }
            }

        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (grid[i][j]==1 && (i-1<0 || i+1>=grid.size() || j-1<0 || j+1>=grid[0].size())){
                    dfs(grid,i,j);
                }
            }
        }
        int count=0;
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};