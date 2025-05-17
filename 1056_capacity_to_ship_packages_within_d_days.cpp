class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int mincap=0;
        int maxcap=0;
        for (int weight:weights){
            mincap=max(mincap,weight);
            maxcap+=weight;
        }
        while(mincap<maxcap){
            int mid=mincap+(maxcap-mincap)/2;// to avoid overlow case
            int sum=0;
            int day=1;
            for (int weight:weights){
                if (sum+weight>mid){
                    day++;
                    sum=0;
                }
                sum+=weight;
            }
            if (day>days){
                mincap=mid+1;
            }
            else{
                maxcap=mid;
            }
            }
            return mincap;
    }
};