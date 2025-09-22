class MinStack {
    stack<long long> st;
    long long minEle = 0;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minEle = val;
        }
        else{
            if(val >= minEle)
                st.push(val);
            else{
                st.push(2ll * val - minEle);
                minEle = val;
            }
        }
    }
    
    void pop() {
        if(st.empty())
            return;
        long long val = st.top();
        if(val < minEle){
            minEle = 2ll * minEle - val;
        }
        st.pop();
    }
    
    int top() {
        if(st.empty())
            return -1;
        else{
            long long val = st.top();
            if(val >= minEle)
                return val;
            else{
                return minEle;
            }
        }
    }
    
    int getMin() {
        if(st.empty())
            return -1;
        return minEle;
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