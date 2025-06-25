class Solution {
public:
    string frequencySort(string s) {
        string c;
        map<char,int >smap;
        for(char c:s){
            smap[c]++;
        }
        vector<pair<char, int>> freqVec(smap.begin(), smap.end());
        sort(freqVec.begin(), freqVec.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });
    for (auto &p : freqVec) {
        c+=string(p.second,p.first);
    }
    return c;
    }
};