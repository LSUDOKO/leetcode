class Solution {
public:
    int count=0;
    void solve(int index,int n,vector<bool>&used){
        if (index>n){
            count++;
            return ;
        }
        for (int i=1;i<=n;i++){
            if (used[i]){
                continue;
            }
            if (i%index!=0 && (index%i)!=0){
                continue;
            }
            used[i]=true;
            solve(index+1,n,used);
            used[i]=false;
        }
    }
    int countArrangement(int n) {
        vector<bool>used(n+1,false);
        solve(1,n,used);
        return count;
    }
};