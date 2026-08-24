class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> prefixSum(n, 0);
        prefixSum[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }

        vector<int> t(n);
        t[n - 1] = prefixSum[n - 1];                       // base case: solve(n-1)
        
        for (int i = n - 2; i >= 1; i--) {
            int take = prefixSum[i] - t[i + 1];
            int skip = t[i+1];

            t[i] = max(take, skip);
        }

        return t[1]; // == solve(1)
    }
};