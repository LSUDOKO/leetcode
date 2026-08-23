class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int leftsum=0;
        int rightsum=0;
        int leftques=0;
        int rightques=0;
        for (int i=0;i<n;i++){
            if (num[i]=='?'){
                if (i<n/2){
                    leftques++;
                }
                else{
                    rightques++;
                }
            }
            else {
                if (i<n/2){
                    leftsum+=num[i]-'0';
                }
                else{
                    rightsum+=num[i]-'0';
                }
            }
        }
        int totalques=leftques+rightques;
        if (totalques%2!=0){
            return true;
        }
        int left=2*leftsum+9*leftques;
        int right=2*rightsum+9*rightques;
        if (left==right){
            return false;
        }
        else{
            return true;
        }
    }
};