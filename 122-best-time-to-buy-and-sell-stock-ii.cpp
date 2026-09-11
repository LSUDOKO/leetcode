class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if (n==1){
            return 0;
        }
        int i=0;
        int j=1;
        int ans=0;
        while(j<n){
            if (prices[i]>prices[j]){
                i++;
                j++;
            }
            else if (prices[i]<=prices[j] && j+1!=n && prices[j]>prices[j+1]){
                ans+=prices[j]-prices[i];
                i=j;
                j++;
            }
            else if (j==(n-1)){
                if (prices[i]<=prices[j]){
                    ans+=prices[j]-prices[i];
                    break;
                }
            }
            else{
                j++;
            }
        }
        // if (i==0 && j==n-1){
        //     ans+=prices[j]-prices[i];
        // }
        return ans;
    }
};