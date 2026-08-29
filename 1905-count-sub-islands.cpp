class Solution {
    void dfs(vector<vector<int>>&grid1,vector<vector<int>>&grid2,bool &issub,int i,int j){
        if (grid1[i][j]==0){
            issub=false;
        }
        grid2[i][j]=0;
        int pr[]={-1,1,0,0};
        int pc[]={0,0,-1,1};
        for (int k=0;k<4;k++){
            int fr=pr[k]+i;
            int fc=pc[k]+j;
            if (fr>=0 && fr<grid2.size() && fc>=0 && fc<grid2[0].size() && grid2[fr][fc]==1){
                dfs(grid1,grid2,issub,fr,fc);
            }
        }
        
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid2.size();
        int n=grid2[0].size();
        int ans=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid2[i][j]==1){
                    bool issub=true;
                    dfs(grid1,grid2,issub,i,j);
                    if(issub){
                        ans++;
                    }
                }
            }
        }
        return ans;

    }
};