class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0;
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j]==1){
                    int row[]={-1,1,0,0};
                    int col[]={0,0,1,-1};
                    for (int k=0;k<4;k++){
                        int r=i+row[k];
                        int c=j+col[k];
                        if (r>=0 && r<grid.size() && c>=0 && c<grid[0].size()){
                            if(grid[r][c]==0){
                                count++;
                            }
                        }
                        else{
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};