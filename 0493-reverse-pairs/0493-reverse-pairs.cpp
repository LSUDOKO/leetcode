class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ans = 0;
    mergeSort(nums, 0, nums.size() - 1, ans);
    return ans;
  }
    private:
    void mergeSort(vector<int>& nums, int l, int r, int& ans) {
    if (l >= r)
      return;
    const int m = (l + r) / 2;
    mergeSort(nums, l, m, ans);
    mergeSort(nums, m + 1, r, ans);
    merge(nums, l, m, r, ans);
  }

  void merge(vector<int>& nums, int l, int m, int r, int& ans) {
    const int lo = m + 1;
    int hi = m + 1;  
    for (int i = l; i <= m; ++i) {
      while (hi <= r && nums[i] > 2L * nums[hi])
        ++hi;
      ans += hi - lo;
    }

    vector<int> sorted(r - l + 1);
    int k = 0;
    int i = l;      
    int j = m + 1;  

    while (i <= m && j <= r)
      if (nums[i] < nums[j])
        sorted[k++] = nums[i++];
      else
        sorted[k++] = nums[j++];
    while (i <= m)
      sorted[k++] = nums[i++];
    while (j <= r)
      sorted[k++] = nums[j++];
    copy(sorted.begin(), sorted.end(), nums.begin() + l);
  }
};