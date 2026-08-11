class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int>pq1;
        priority_queue<int>pq2;
        string temp=to_string(num);
        for (char &ch:temp){
            int number=ch-'0';
            if (number%2==0){
                pq1.push(number);
            }
            else{
                pq2.push(number);
            }
        }
        for (char &ch:temp){
            int number=ch-'0';
            if (number%2==0){
                int toper=pq1.top();
                ch=toper+'0';
                pq1.pop();
            }
            else {
                int toper=pq2.top();
                ch=toper+'0';
                pq2.pop();
        }
        }
        return stoi(temp);
    }
};