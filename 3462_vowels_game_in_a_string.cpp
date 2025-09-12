class Solution {
public:
    bool doesAliceWin(string s) {
        int count=0;
        for (char &c :s){
            if (c=='a'|| c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='o' ||c=='O' ||c=='U' ||c=='u'){
                    count++;
            }
        }
        if (count==0){
            return false;
        }
        else {
            return true;
        }
    }
};