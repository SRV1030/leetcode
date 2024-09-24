class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>st;
        for(auto&i:arr1){
            while(i>0){
                st.insert(i);
                i/=10;
            }
        }
        int mx=0;
        for(auto&i:arr2){
            while(!st.count(i) && i>0){
                i/=10;
            }
            if(i>0)mx=max(mx,(int)(log10(i)+1));
        }
        return mx;
    }
};