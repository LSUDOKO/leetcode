class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>st(m,string(n,'#'));
        for (int i=0;i<m;i++){
            st[i][0]='.';
        }
        for(int j=0;j<n;j++){
            st[m-1][j]='.';
        }
        return st;
    }
};