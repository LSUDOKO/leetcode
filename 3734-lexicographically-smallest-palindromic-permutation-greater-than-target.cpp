class Solution {
public:

    string result = "";
    char midChar = '$';
    int half = 0;

    bool solve(string& curr, vector<int>& count, string& target, int i, bool greater) {
        if (i == half) {

            string candidate = curr;
            string rightHalf = candidate;
            reverse(begin(rightHalf), end(rightHalf));
            
            if(midChar != '$')
                candidate += midChar;

            candidate += rightHalf;

            if (candidate > target) {
                result = candidate;
                return true;
            }

            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (count[ch - 'a'] == 0)
                continue;

            if (!greater && ch < target[i])
                continue;

            curr.push_back(ch);
            count[ch - 'a']--;

            bool isGreater = greater || ch > target[i];

            if (solve(curr, count, target, i + 1, isGreater))
                return true;

            curr.pop_back();
            count[ch - 'a']++;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        
        for (char ch : s) 
            count[ch - 'a']++;

        int oddCount = 0;
        for (int c = 0; c < 26; c++) {
            if (count[c] % 2 == 1) { 
                oddCount++; 
                midChar = c + 'a'; 
            }
        }
        if (oddCount > 1) 
            return "";

        vector<int> halfCount(26, 0);
        for (int c = 0; c < 26; c++) {
            halfCount[c] = count[c] / 2;
        }

        half = n / 2;

        string curr;
        solve(curr, halfCount, target, 0, false);
        return result;
    }
};