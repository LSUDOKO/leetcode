class Solution {
public:
    int mySqrt(int n) {
        long  low = 1, high = n;
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long square = mid * mid;

            if (square <= n) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};