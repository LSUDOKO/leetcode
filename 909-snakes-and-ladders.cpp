class Solution {
    int n;
    pair<int,int> getcord(int num){
        int rt=(num-1)/n;
        int rb=(n-1)-rt;
        int col=(num-1)%n;
        if (((n%2==1) && (rb%2==1))||(n%2==0 && rb%2==0)){
            col=(n-1)-col;
        }
        return make_pair(rb,col);
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();
        int steps=0;
        queue<int>q;
        vector<bool>vis(n*n+1,false);
        q.push(1);
        vis[1]=true;
        while(!q.empty()){
            int a=q.size();
            while(a--){
                int x=q.front();
                q.pop();
                if (x==n*n){
                    return steps;
                }
                for (int i=1;i<=6;i++){
                    int val=x+i;
                    if (val>n*n){
                        break;
                    }
                    pair<int,int>cord=getcord(val);
                    int r=cord.first;
                    int c=cord.second;
                    int next;
                    if(board[r][c]==-1){
                        next=val;
                    }
                    else{
                        next=board[r][c];
                    }
                    auto nextcord=getcord(next);
                    if (vis[next]){
                        continue;
                    }
                    vis[next]=true;
                    q.push(next);
                }

            }
            steps++;
            
        }

        return -1;
    }
};