class MinStack {

    public Stack<Integer> a, b;
    public MinStack() {
        a = new Stack<>();
        b = new Stack<>();
    }
    
    public void push(int val) {
        a.push(val);
        if (b.empty() || val <= b.peek()) {
            b.push(val);
        }
    }
    
    public void pop() {
        if (!a.empty()) {
            if (a.peek().intValue() == b.peek().intValue()) {
                b.pop();
            }
            a.pop();
        }
    }
    
    public int top() {
        return a.peek();
    }
    
    public int getMin() {
        return b.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */