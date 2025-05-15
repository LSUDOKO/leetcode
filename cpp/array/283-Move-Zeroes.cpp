class Solution {
public:
    void moveZeroes(vector<int>& arr) {
    int count = 0;  
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0)
            arr[count++] = arr[i];
    }
    while (count < arr.size())
        arr[count++] = 0;}
};