class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>mp;
        for(auto&i:nums2){
            while(!st.empty() && st.top()<i){
                mp[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        vector<int> ans;
        for(auto&i:nums1) ans.push_back(mp.count(i)?mp[i]:-1);
        return ans;
    }
};