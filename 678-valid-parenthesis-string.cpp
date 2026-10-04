
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> t(n, vector<int>(n + 1, -1));
        return isValidString(0, 0, s, t);
    }

    bool isValidString(int idx, int open, string &str, vector<vector<int>> &t) {
        if (open < 0) return false;
        if (open > str.size() - idx) return false;

        if (idx == str.size()) {
            return open == 0;
        }

        if (t[idx][open] != -1) {
            return t[idx][open] == 1;
        }

        bool isValid = false;

        if (str[idx] == '*') {
            isValid |= isValidString(idx + 1, open + 1, str, t);

            if (open > 0) {
                isValid |= isValidString(idx + 1, open - 1, str, t);
            }

            isValid |= isValidString(idx + 1, open, str, t);
        } 
        else if (str[idx] == '(') {
            isValid = isValidString(idx + 1, open + 1, str, t);
        } 
        else {
            if (open > 0) {
                isValid = isValidString(idx + 1, open - 1, str, t);
            }
        }

        t[idx][open] = isValid ? 1 : 0;
        return isValid;
    }
};