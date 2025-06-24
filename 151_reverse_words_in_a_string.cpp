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
        stringstream ss(s);
        string word;
        string b = "";

        while (ss >> word) {
            b = word + " " + b;  
        }

        b = trim(b);
        return b;
    }
};