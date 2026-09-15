class Solution {
public:
    vector<vector<bool>> isPalindrome;
    vector<int> t;
    int maxPalindromes(string s, int k) {
        int n = s.length();
        isPalindrome.assign(n+1, vector<bool>(n+1, false));
        for (int L = 1; L <= n; L++) {
            for (int i = 0; i + L <= n; i++) {
                int j = i + L - 1;

                if (i == j) {
                    isPalindrome[i][i] = true;
                } else if (i + 1 == j) {
                    isPalindrome[i][j] = (s[i] == s[j]);
                } else {
                    isPalindrome[i][j] = ((s[i] == s[j]) && isPalindrome[i+1][j-1] == true);
                }
            }
        }

        t.assign(n+1, -1);
        
        for(int len = 0; len < k; len++) {
            t[len] = 0;
        }

        for(int len = k; len <= n; len++) {
            int result = t[len-1];

            int j = len-1;
            for(int i = 0; j-i+1 >= k; i++) {
                if(isPalindrome[i][j]) {
                    result = max(result, 1 + t[i]);
                }
            }

            t[len] = result;
        }

        return t[n];

    }
};