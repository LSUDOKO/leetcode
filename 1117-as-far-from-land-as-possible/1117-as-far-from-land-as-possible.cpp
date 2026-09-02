class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>>q;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }   
        if (q.empty() || q.size()==n*n){
            return -1;
        }
        int dis=-1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [r,c]=q.front();
                q.pop();
                int pr[]={-1,1,0,0};
                int pc[]={0,0,-1,1};
                for (int i=0;i<4;i++){
                    int row=pr[i]+r;
                    int col=pc[i]+c;
                    if (row>=0 && row<n && col>=0 && col<n && grid[row][col]==0){
                        grid[row][col]=1;
                        q.push({row,col});
                    }
                }
            }
            dis++;
        }
        return dis;
    }
};