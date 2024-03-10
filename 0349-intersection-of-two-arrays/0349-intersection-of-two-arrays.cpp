class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> ans,st(begin(nums1),end(nums1));
        for(auto&i:nums2){
            if(st.count(i))ans.insert(i);
        }
        return vector<int>(begin(ans),end(ans));
    }
};