// class Solution {
// public:
//     vector<int> replaceNonCoprimes(vector<int>& nums) {
//         int i=1;
//         int n=nums.size();
//         int a=nums[nums.size()-1];
//         while(n--){
//             if (nums[i]%nums[i-1]==0 ||nums[i-1]%nums[i]==0){
//                 int b=nums[i];
//                 if (nums[i]%nums[i-1]==0){
//                     nums[i-1]=nums[i];
//                     nums.erase(remove(nums.begin(), nums.end(), nums[i]), nums.end());
//                     if (b==a){
//                     break;
//                     }
//                 }
//                 else {
//                     nums[i-1]=nums[i-1];
//                     nums.erase(remove(nums.begin(), nums.end(), nums[i]), nums.end());
//                     if (b==a){
//                     break;
//                     }
//                 }
//             }
            
//             else{
//                 i=i+2;
//             }
//         }
//         return nums;
//     }
// };
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int i = 1;
        while (i < nums.size()) {
            int g = gcd(nums[i], nums[i-1]);
            if (g > 1) {
                long long merged = 1LL * nums[i] / g * nums[i-1];
                nums[i-1] = merged;
                nums.erase(nums.begin() + i);  
            
                if (i > 1) i--;
            } else {
                i++;
            }
        }
        return nums;
    }
};