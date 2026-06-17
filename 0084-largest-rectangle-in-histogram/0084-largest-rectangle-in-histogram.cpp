class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        for(int index = 0; index <= heights.size(); ++index){
            while(!st.empty() && (index == heights.size() || heights[st.top()] > heights[index])){
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? index : index - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(index);
        }
        return maxArea;
    }
};