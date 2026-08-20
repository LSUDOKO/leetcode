class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for (int i=2;i<nums.size();i++){
            if (arr1.back()>arr2.back()){
                arr1.push_back(nums[i]);
            }
            else{
                arr2.push_back(nums[i]);
            }
        }
        for (int i=0;i<arr2.size();i++){
            arr1.push_back(arr2[i]);
        }
        return arr1;
    }
};