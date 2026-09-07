class Solution {
public:
    int M = 1e9+7;
    int dp[2001];
    vector<int> prev;
    int distinctSubseqII(string s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        prev.assign(n+1, 0);
        vector<int> lastSeen(26, 0);
        for(int i = 1; i <= n; i++) {
            int idx = s[i-1] -'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            int total = (2 * dp[i-1]) % M;
            if(prev[i] != 0) {
                int duplicates = dp[prev[i] - 1];
                total = (total - duplicates + M) % M;
            }
            dp[i] = total;
        }
        return (dp[n] - 1 + M) % M;
    }
};