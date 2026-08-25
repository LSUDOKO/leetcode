class Solution {
public:
    int checkStraightLine(vector<vector<int>>& coordinates,int &count) {
        int n = coordinates.size();
        count=1;
        long long  x1 = coordinates[0][0];
        long long  y1 = coordinates[0][1];
        long long x2 = coordinates[1][0];
        long long y2 = coordinates[1][1];
        for (int i = 2; i < n; i++) {
            long long  x3 = coordinates[i][0];
            long long y3 = coordinates[i][1];
            if ((y2 - y1) * (x3 - x2) !=
                (y3 - y2) * (x2 - x1)) {
                count++;}
            x1=x2;
            y1=y2;
            x2=x3;
            y2=y3;
        }
        return count;
    }
    int minimumLines(vector<vector<int>>& stprice) {
        int n=stprice.size();
        if (n==1){
            return 0;
        }
        else if (n==2){
            return 1;
        }
        else{
            int count=0;
            sort(stprice.begin(),stprice.end());
            return checkStraightLine(stprice,count);
        }
    }
};