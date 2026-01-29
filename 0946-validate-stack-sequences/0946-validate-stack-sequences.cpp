class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        for(int index = 0, pop = 0; index < pushed.size(); ++index){
            st.push(pushed[index]);
            while(!st.empty() && pop < popped.size() && st.top() == popped[pop]){
                ++pop;
                st.pop();
            }
        }
        return st.empty();
    }
};