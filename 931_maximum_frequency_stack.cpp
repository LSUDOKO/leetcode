class FreqStack {
public:
    unordered_map<int,int> freq;//value->freq
    unordered_map<int,stack<int>>ans;//freq->stack<values>
    int maxi;
    FreqStack() {
        maxi=0;
    }
    
    void push(int val) {
        int fre=freq[val]++;
        maxi=max(maxi,fre);
        ans[fre].push(val);
    }
    
    int pop() {
        int val=ans[maxi].top();
        ans[maxi].pop();
        freq[val]--;
        if (ans[maxi].empty()){
            maxi--;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */