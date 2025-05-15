class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        unordered_set<int> sa(a.begin(), a.end());  
        vector<int> res;                            
        for (int i = 0; i < b.size(); i++) {
            if (sa.find(b[i]) != sa.end()) {
                res.push_back(b[i]); 
                sa.erase(b[i]);  
            }
        }
        return res;
    }
};