class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (grid[i][j]==2){
                    q.push({i,j});
                }
                else if (grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if (fresh==0){
            return 0;
        }
        int pr[]={1,-1,0,0};
        int pc[]={0,0,1,-1};
        int minutes=0;
        while(!q.empty()){
            int size=q.size();
            bool rotten=false;
            for (int i=0;i<size;i++){
                auto [r,c]=q.front();
                q.pop();
                for (int i=0;i<4;i++){
                    int fr=r+pr[i];
                    int fc=c+pc[i];
                    if (fr>=0 && fr<grid.size() && fc>=0 && fc<grid[0].size()){
                        if (grid[fr][fc]==1){
                            grid[fr][fc]=2;
                            fresh--;
                            rotten=true;
                            q.push({fr,fc});
                        }
                    }
                }

                
            }
            if (rotten){
                minutes++;
            }
            
            
        }
        if (fresh>0){
            return -1;
        }
        return minutes;
    }
};