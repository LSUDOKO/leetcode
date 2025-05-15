class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int l = 1;
    int r = ranges::max(piles);

    while (l < r) {
      int m = (l + r) / 2;
      if (eatHours(piles, m) <= h)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  int eatHours(const vector<int>& piles, int m) {
    return accumulate(piles.begin(), piles.end(), 0, [&](int acc, int pile) {
      return acc + (pile - 1) / m + 1; 
    });
  }
};