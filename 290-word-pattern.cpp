class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        stringstream ss(s);
        string temp;
        while(ss>>temp){
            words.push_back(temp);
        }
        if (pattern.size()!=words.size()){
            return false;
        }
        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;
        for (int i=0;i<pattern.size();i++){
            char ch=pattern[i];
            string word=words[i];
            if (mp1.count(ch)&& mp1[ch]!=word){
                return false;
            }
            if (mp2.count(word) && mp2[word]!=ch){
                return false;
            }
            mp1[ch]=word;
            mp2[word]=ch;
        }
        return true;

    }
};