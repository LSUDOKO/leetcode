class Solution {
public:
    void dfs(vector<vector<int>>&grid,int row,int col,int &area){
        grid[row][col]=0;
        int r[]={-1,1,0,0};
        int c[]={0,0,1,-1};
        for (int i=0;i<4;i++){
            int fr=row+r[i];
            int fc=col+c[i];
            if (fr>=0 && fr<grid.size() && fc>=0 && fc<grid[0].size()){
                if(grid[fr][fc]==1){
                    area++;
                    dfs(grid,fr,fc,area);
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result=0;
        for(int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j]==1){
                    int area=1;
                    dfs(grid,i,j,area);
                    result=max(result,area);
                }
            }
        }
        return result;
    }
};