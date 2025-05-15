class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int maxPro = 0;
        int n = arr.size();
        int minPrice = INT_MAX;
        for (int i = 0; i < arr.size(); i++) {
            minPrice = min(minPrice, arr[i]);
            maxPro = max(maxPro, arr[i] - minPrice);
        }
        return maxPro;
    }
};