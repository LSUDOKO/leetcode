class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;

        for (int i = 1; i < n; i++) {
            int j = n - i;
            if (hasNoZero(i) && hasNoZero(j)) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
        
        return ans;
    }
    
private:
    bool hasNoZero(int num) {
        while (num > 0) {
            if (num % 10 == 0) return false;
            num /= 10;
        }
        return true;
    }
};