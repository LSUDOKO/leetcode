class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
    return nums;
  }

 private:
  void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r)
      return;

    const int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }

  void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> temp;     
    int i = l;      
    int j = m + 1;  

    while (i <= m && j <= r){
      if (arr[i] < arr[j]){
        temp.push_back(arr[i]);
        i++;}
      else{
        temp.push_back(arr[j]);
        j++;}}

    // Put the possible remaining left part into the sorted array.
    while (i <= m){
        temp.push_back(arr[i]);
        i++;}

    // Put the possible remaining right part into the sorted array.
    while (j <= r){
        temp.push_back(arr[j]);
        j++;}
    for (int i = l; i <= r; i++) {
        arr[i] = temp[i - l];
    }
  }
    
};