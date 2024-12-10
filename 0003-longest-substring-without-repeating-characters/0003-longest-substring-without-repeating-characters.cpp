class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,n=size(s),mx=0;
        unordered_set<char>st;
        while(r<n){
            while(st.count(s[r])){
                st.erase(s[l++]);
            }
            st.insert(s[r++]);
            mx=max(mx,(int)st.size());
        }
        return mx;
    }
};