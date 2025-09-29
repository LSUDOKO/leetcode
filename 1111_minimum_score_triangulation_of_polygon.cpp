class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        // sort(values.begin(),values.end());
        // int a=values[0];
        // int b=values[1];
        // int final_max=0;
        // for (int i=2;i<values.size();i++){
        //     int max_product=a*b;
        //     max_product*=values[i];
        //     final_max+=max_product;
        // }
        // return final_max;
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int len = 2; len < n; len++) {
            for (int i = 0; i + len < n; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], 
                        dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
                }
            }
        }
        return dp[0][n-1];
    }
};