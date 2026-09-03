class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int miniodd=-1;
        for (int i=0;i<nums1.size();i++){
            if (nums1[i]%2!=0){
                if (miniodd==-1){
                    miniodd=nums1[i];
                }
                else if (miniodd>nums1[i]){
                    miniodd=nums1[i];
                }
            }
        }
        if (miniodd==-1){
            return true;
        }
        for (int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0 && nums1[i]<=miniodd){
                return false;
            }
        }
        return true;
    }
};