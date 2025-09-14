class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string, string> cap;   
        unordered_map<string, string> vowel; 

        auto devowel = [](const string& s) {
            string t = s;
            for (char& c : t) {
                char low = tolower(c);
                if (low == 'a' || low == 'e' || low == 'i' ||
                    low == 'o' || low == 'u') c = '*';
            }
            return t;
        };

        for (const string& w : wordlist) {
            exact.insert(w);

            string low;
            low.reserve(w.size());
            for (char c : w) low += tolower(c);

            if (!cap.count(low)) cap[low] = w;

            string mask = devowel(low);
            if (!vowel.count(mask)) vowel[mask] = w;
        }

        vector<string> ans;
        ans.reserve(queries.size());

        for (const string& q : queries) {
            if (exact.count(q)) { ans.push_back(q); continue; }

            string low;
            low.reserve(q.size());
            for (char c : q) low += tolower(c);

            auto it = cap.find(low);
            if (it != cap.end()) { ans.push_back(it->second); continue; }

            string mask = devowel(low);
            auto jt = vowel.find(mask);
            if (jt != vowel.end()) { ans.push_back(jt->second); continue; }

            ans.push_back("");
        }
        return ans;
    }
};