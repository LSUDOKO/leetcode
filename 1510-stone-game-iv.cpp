class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> t(n+1, false);

        t[0] = false;

        for(int i = 1; i < n+1; i++) {

            for(int k = 1; k*k <= i; k++) {
                if(t[i - (k*k)] == false) {
                    t[i] = true;
                    break;
                }
            }
        }

        return t[n];
    }
};