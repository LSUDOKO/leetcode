class Solution {
public:
    bool isPalindrome(int n) {
        long revNum = 0;
        long dup = n;
        while (n > 0) {
            revNum = (revNum * 10) + n % 10;
            n = n / 10;
        }
        if (dup == revNum) {
            return true;
        } else {
            return false;
        }
        }
};