class Solution {
public:
    string trim(string s) {
        while (!s.empty() && isspace(s.front()))
            s.erase(s.begin());
        while (!s.empty() && isspace(s.back()))
            s.pop_back();
        return s;
    }

    string reverseWords(string s) {
        s = trim(s);
        stringstream ss(s);
        string word;
        vector<string> words;

        while (ss >> word) {
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        string result;
        for (int i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i != words.size() - 1)
                result += " ";
        }

        return result;
    }
};