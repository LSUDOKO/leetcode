class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()){
            return false;
        }
        else{
            map<char,int>smap;
            map<char ,int>tmap;
            for (char c:s){
                smap[c]++;
            }
            for (char c:t){
                tmap[c]++;
            }
            if (smap==tmap){
                return true;
            }
            else {
                return false;
            }
        }
    }
};