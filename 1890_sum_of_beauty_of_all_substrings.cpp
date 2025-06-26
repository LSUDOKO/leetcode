class Solution {
public:
    int beautySum(string s) {
        int total = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            vector<int> freq(26, 0);  

            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++;  

                int maxFreq = 0, minFreq = INT_MAX;
                for (int f : freq) {
                    if (f > 0) {
                        maxFreq = max(maxFreq, f);
                        minFreq = min(minFreq, f);
                    }
                }

                total += (maxFreq - minFreq);
            }
        }

        return total;
    }
};