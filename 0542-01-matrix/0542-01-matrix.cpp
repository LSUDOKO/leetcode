class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>>q;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (mat[i][j]==0){
                    q.push({i,j});
                }
                else{
                    mat[i][j]=-1;
                }
            }
        }
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
                    if (row>=0 && row<m && col>=0 && col<n && mat[row][col]==-1){
                        mat[row][col]=mat[r][c]+1;
                        q.push({row,col});
                    }
                }
            }
        }
        return mat;
    }
};