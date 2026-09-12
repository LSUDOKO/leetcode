class Solution {
public:
    int n;
    vector<int> nextIdx;

    struct Node {
        long long score = -1;
        vector<int> idxs;
    };

    vector<vector<Node>> t;

    int findNext(vector<vector<int>>& intervals, int r) {
        int lo = 0, hi = n - 1;
        int result = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (intervals[mid][0] > r) {
                result = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        for (int i = 0; i < n; i++)
            intervals[i].push_back(i);

        sort(intervals.begin(), intervals.end());

        nextIdx.resize(n);
        for (int i = 0; i < n; i++) {
            int r = intervals[i][1];
            nextIdx[i] = findNext(intervals, r);
        }

        const int K = 4;

        t.assign(n + 1, vector<Node>(K + 1));

        for (int i = n - 1; i >= 0; i--) {
            int weight = intervals[i][2];
            int idx    = intervals[i][3];
            int j      = nextIdx[i];

            for (int k = 1; k <= K; k++) {
                Node skip = t[i + 1][k];
                Node temp = t[j][k - 1];

                Node take;
                take.score = temp.score + weight;
                take.idxs  = temp.idxs;
                take.idxs.push_back(idx);
                sort(begin(take.idxs), end(take.idxs));

                Node result;
                if (skip.score > take.score) {
                    result = skip;
                } else if (skip.score < take.score) {
                    result = take;
                } else {
                    result = (skip.idxs < take.idxs) ? skip : take;
                }

                t[i][k] = result;
            }
        }

        return t[0][K].idxs;
    }
};