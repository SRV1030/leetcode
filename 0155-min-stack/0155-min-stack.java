class MinStack {
    Deque<Long> stack;
    long minVal;

    public MinStack() {
        stack = new ArrayDeque<>();
    }
    
    public void push(int val) {
        long value = val;

        if (stack.isEmpty()) {
            stack.push(value);
            minVal = value;
        } else if (value >= minVal) {
            stack.push(value);
        } else {
            stack.push(2 * value - minVal);
            minVal = value;
        }
    }
    
    public void pop() {
        long val = stack.pop();
        if (val < minVal) {
            minVal = 2 * minVal - val;
        }
    }
    
    public int top() {
        long val = stack.peek();
        if (val < minVal)
            return (int) minVal;
        return (int) val;
    }
    
    public int getMin() {
        return (int) minVal;
    }
}
