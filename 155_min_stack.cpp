class MinStack {
public:
    stack<int>st;
    stack<int>ans;
    MinStack() {
        // this->st=st;
        // this->ans=ans;
        
    }
    
    void push(int val) {
        st.push(val);
        if (ans.empty() || val <= ans.top()) {
            ans.push(val);
        }
    }
    
    void pop() {
        if (st.empty()){
            return ;
        }
        if (st.top()==ans.top()){
            ans.pop();
        }
        st.pop();
    }
    
    int top() {
        if (st.empty()){
            return -1;
        }
        int a=st.top();
        return a;

    }
    
    int getMin() {
        if (ans.empty()) return -1;
        return ans.top() ;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */