class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int>st;
        int n=size(nums),ans=0;
        for(int i=0;i<n;++i){
            if(st.empty() || nums[st.top()]>nums[i]) st.push(i);
        }
        for(int i=n-1;i>=0;--i){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                ans=max(ans,i-st.top());
                st.pop();
            }
            if(st.empty()) return ans;
        }
        return ans;
    }
};