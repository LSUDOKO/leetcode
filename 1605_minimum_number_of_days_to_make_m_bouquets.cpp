class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n) {
            return -1;
        }
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        
        while (left < right) {
            int mid = (left + right)/ 2;
            if (canMakeBouquets(bloomDay, mid, m, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
private:
    bool canMakeBouquets(vector<int>& bloomDay, int day, int m, int k) {
        int bouquets = 0;
        int adjacentFlowers = 0;
        for (int bloom : bloomDay) {
            if (bloom <= day) {
                adjacentFlowers++;
                if (adjacentFlowers == k) {
                    bouquets++;
                    adjacentFlowers = 0;
                }
            } else {
                adjacentFlowers = 0;
            }
        }
        return bouquets >= m;
    }
};