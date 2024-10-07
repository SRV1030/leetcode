class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(auto&i:s){
            if(i=='B' && !st.empty() && st.top()=='A')st.pop();
            else if(i=='D' && !st.empty() && st.top()=='C')st.pop();
            else st.push(i);
        }
        return size(st);
    }
};