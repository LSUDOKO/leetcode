class Solution {
    int result=-1;
    void dfs(int u,vector<int>&edges,vector<bool>&visited,vector<bool>&inrecursion,vector<int>&count){
        if (u!=-1){
            visited[u]=true;
            inrecursion[u]=true;
            int v=edges[u];
            if(v!= -1 && !visited[v]){
                count[v]=count[u]+1;
                dfs(v,edges,visited,inrecursion,count);
            }
            else if(v!=-1 && inrecursion[v]==true){
                result=max(result,count[u]-count[v]+1);
            }
            inrecursion[u]=false;
        }
    }
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<bool>visited(n,false);
        vector<bool>inrecursion(n,false);
        vector<int>count(n,1);
        for (int i=0;i<n;i++){
            if (!visited[i]){
                dfs(i,edges,visited,inrecursion,count);
            }
        }
        return result;
    }
};