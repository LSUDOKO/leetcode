class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n = s.size();
        int whiteCount = 0;

        for (int i = 0; i < k; i++) {
            if (s[i] == 'W') whiteCount++;
        }

        int ans = whiteCount;

        for (int i = k; i < n; i++) {
            if (s[i - k] == 'W') whiteCount--; 
            if (s[i] == 'W') whiteCount++;
            ans = min(ans, whiteCount);
        }

        return ans;
    }
};