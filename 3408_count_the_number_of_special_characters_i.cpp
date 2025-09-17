class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        vector<int> small(26, 0);
        vector<int> big(26, 0);

        for (int i = 0; i < word.size(); i++) {
            if (islower(word[i])) {
                small[word[i] - 'a']++;
            } else if (isupper(word[i])) {
                big[word[i] - 'A']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (small[i] > 0 && big[i] > 0) {
                count++;
            }
        }
        return count;
    }
};