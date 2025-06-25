class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int ma = 0; 

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;
                ma = max(ma, count);
            } else if (s[i] == ')') {
                count--;
            }
        }

        return ma;
    }
};