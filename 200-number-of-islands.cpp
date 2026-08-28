class Solution {
    void dfs(vector<vector<char>>&grid,int r , int c){
        grid[r][c]='0';
        int row[]={-1,1,0,0};
        int col[]={0,0,1,-1};
        for (int i=0;i<4;i++){
            int fr=r+row[i];
            int fc=c+col[i];
            if (fr>=0 && fr<grid.size() && fc>=0 && fc<grid[0].size()){
                if(grid[fr][fc]=='1'){
                    dfs(grid,fr,fc);
                }
            }
        }
    }
public:
    
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};