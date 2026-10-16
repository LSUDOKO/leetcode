
class Solution {
    static const int MOD = 1'000'000'007;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1LL;

        tree[node].sq = (
            tree[node].sq
            + 2LL * val * tree[node].sum
            + val * val % MOD * len
        ) % MOD;

        tree[node].sum = (
            tree[node].sum + val * len
        ) % MOD;

        tree[node].lazy = (tree[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;
        long long val = tree[node].lazy;

        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        tree[node].lazy = 0;
    }

    void pull(int node) {
        tree[node].sum = (
            tree[node * 2].sum + tree[node * 2 + 1].sum
        ) % MOD;

        tree[node].sq = (
            tree[node * 2].sq + tree[node * 2 + 1].sq
        ) % MOD;
    }

    void update(int node, int l, int r,
                int ql, int qr, long long val) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        pull(node);
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, Node());

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int j = 0; j < n; j++) {
            int x = nums[j];
            update(1, 0, n - 1, last[x] + 1, j, 1);
            ans = (ans + tree[1].sq) % MOD;

            last[x] = j;
        }

        return ans;
    }
};
