class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mn = INT_MAX,unique = 0;
        set<int>st;
        for(auto&i:nums){
            mn=min(i,mn);
            st.insert(i);
        }
        unique = st.size();
        return mn<k?-1:mn==k?unique-1:unique;
    }
};