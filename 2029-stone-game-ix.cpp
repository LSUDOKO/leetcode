class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3]={};
        for (int x:stones){
            cnt[x%3]++;
        }
        int a=cnt[1];
        int b=cnt[2];
        int c=cnt[0];
        if (c%2==0)
            return cnt[1]>=1 && cnt[2]>=1;
        else return abs(cnt[1]-cnt[2])>=3;

    }
};