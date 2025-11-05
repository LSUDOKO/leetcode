class Solution {
public:
    vector<int> findXSum(vector<int>& a, int k, int x) {
        int n = a.size();
        vector<int> res;
        for (int i = 0; i + k <= n; i++) {
            unordered_map<int,int> f;
            for (int j = i; j < i + k; j++) f[a[j]]++;
            vector<pair<int,int>> v(f.begin(), f.end());
            sort(v.begin(), v.end(), [](auto &p1, auto &p2){
                if (p1.second == p2.second) return p1.first > p2.first;
                return p1.second > p2.second;
            });
            int s = 0, c = 0;
            for (auto &p : v) {
                if (c == x) break;
                s += p.first * p.second;
                c++;
            }
            res.push_back(s);
        }
        return res;
    }
};