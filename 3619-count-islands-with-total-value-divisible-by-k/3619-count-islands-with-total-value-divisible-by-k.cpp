class Solution {
    void dfs(vector<vector<int>>& grid,int i, int j,long long &sum){
        sum+=grid[i][j];
        grid[i][j]=0;
        int row[]={-1,1,0,0};
        int col[]={0,0,-1,1};
        for (int m=0;m<4;m++){
            int fr=i+row[m];
            int fc=j+col[m];
            if (fr>=0 && fr<grid.size() && fc>=0 && fc<grid[0].size()){
                if(grid[fr][fc]!=0){
                    dfs(grid,fr,fc,sum);
                }
            }
        }
    }
    public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int count=0;
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j]!=0){
                    long long sum=0;
                    dfs(grid,i,j,sum);
                    if (sum%k==0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};