class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj,int u,vector<bool>&vis){
        if (vis[u]) return ;
        vis[u]=true;
        for (int v:adj[u]){
            if (!vis[v]){
                dfs(adj,v,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        unordered_map<int,vector<int>>adj;
        for (int i=0;i<rooms.size();i++){
            for (int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
        vector<bool>vis(n,false);
        dfs(adj,0,vis);
        for (int i=0;i<n;i++){
            if(vis[i]==false){
                return false;
            }
        }
        return true;
    }
};