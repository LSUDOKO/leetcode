class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int>st(10,0);
        for (int digit:digits){
            st[digit]++;
        }
        int count=0;
        for (int i=100;i<=998;i+=2){
            int d1=i/100;
            int d2=(i/10)%10;
            int d3=i%10;
            vector<int>need(10,0);
            need[d1]++;
            need[d2]++;
            need[d3]++;
            if (need[d1]<=st[d1] && need[d2]<=st[d2]&& need[d3]<=st[d3]){
                count++;
            }
        }
        return count;
    }
};