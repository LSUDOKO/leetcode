class Solution {
public:
    using VB=vector<bool>;
    using VVB=vector<VB>;
    using VVVB=vector<VVB>;
    using VVVVB=vector<VVVB>;

    vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};

    struct State{
        int row;
        int col;
        int energyleft;
        int collectedmask;
    };

    int minMoves(vector<string>& classroom,int energy){
        int m=classroom.size();
        int n=classroom[0].size();
        int maxenergy=energy;
        int litterbit[20][20];
        int littercount=0;
        int startr=0;
        int startc=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                litterbit[i][j]=-1;

                if(classroom[i][j]=='S'){
                    startr=i;
                    startc=j;
                }
                else if(classroom[i][j]=='L'){
                    litterbit[i][j]=littercount;
                    littercount++;
                }
            }
        }

        int allcollected=(1<<littercount)-1;

        if(littercount==0){
            return 0;
        }

        VVVVB visited(m,VVVB(n,VVB(maxenergy+1,VB(1<<littercount,false))));

        queue<State>q;
        q.push({startr,startc,maxenergy,0});
        visited[startr][startc][maxenergy][0]=true;

        int moves=0;

        while(!q.empty()){
            int currsize=q.size();

            while(currsize--){
                State curr=q.front();
                q.pop();

                if(curr.collectedmask==allcollected){
                    return moves;
                }

                if(curr.energyleft==0){
                    continue;
                }

                for(auto &dir:directions){
                    int nextrow=curr.row+dir[0];
                    int nextcol=curr.col+dir[1];

                    if(nextrow<0||nextrow>=m||nextcol<0||nextcol>=n){
                        continue;
                    }

                    char cell=classroom[nextrow][nextcol];

                    if(cell=='X'){
                        continue;
                    }

                    int nextenergy=curr.energyleft-1;
                    int nextcollectmask=curr.collectedmask;

                    if(cell=='R'){
                        nextenergy=maxenergy;
                    }
                    else if(cell=='L'){
                        nextcollectmask|=(1<<litterbit[nextrow][nextcol]);
                    }

                    if(!visited[nextrow][nextcol][nextenergy][nextcollectmask]){
                        visited[nextrow][nextcol][nextenergy][nextcollectmask]=true;

                        q.push({nextrow,nextcol,nextenergy,nextcollectmask});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};