class Solution {
public:
    void dfs(vector<vector<int>>&image,int sr,int sc,int color,int original){
        image[sr][sc]=color;
        int dr[]={-1,1,0,0};
        int ds[]={0,0,-1,1};
        for (int i=0;i<4;i++){
            int r=sr+dr[i];
            int c=sc+ds[i];
            if (r>=0 && r<image.size() && c>=0 && c<image[0].size()){
                if(image[r][c]==original){
                    dfs(image,r,c,color,original);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original=image[sr][sc];
        if (original==color){
            return image;
        }
        dfs(image,sr,sc,color,original);
        return image;
    }
};