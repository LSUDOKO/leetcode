class CustomStack {
public:
    stack<int>ans;
    int maxi;
    CustomStack(int maxSize) {
        maxi=maxSize;
    }
    
    void push(int x) {
        if (ans.size()==maxi){
            return;
        }
        ans.push(x);
    }
    
    int pop() {
        int top;
        if(ans.empty()){
            return -1;
        }
        else{
            top=ans.top();
            ans.pop();
        }
    return top;
    }
    
    void increment(int k, int val) {
        stack<int> temp;
        int n = ans.size();

        while (!ans.empty()) {
            temp.push(ans.top());
            ans.pop();
        }

        int limit = min(k, n);
        for (int i = 1; i <= n; ++i) {
            int cur = temp.top();
            temp.pop();
            if (i <= limit) cur += val;
            ans.push(cur); 
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */