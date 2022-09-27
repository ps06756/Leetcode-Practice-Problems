class MinStack {
public:
    stack<int> a, b;
    MinStack() {
        
    }
    
    void push(int val) {
        a.push(val);
        
        if (b.size() == 0 || val <= b.top()) {
            b.push(val);
        }
    }
    
    void pop() {
        if (a.size() >= 1) {
            if (a.top() == b.top()) {
                b.pop();
            }
            a.pop();
        }
    }
    
    int top() {
        return a.top();
    }
    
    int getMin() {
        return b.top();
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