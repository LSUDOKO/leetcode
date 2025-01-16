class Solution {
public:
    int majorityElement(vector<int>&v) {
    int n = v.size();
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
    }
    for (auto it : mpp) {
        if (it.second > (n / 2)) {
            return it.first;
        }
    }

    return -1;
}
};