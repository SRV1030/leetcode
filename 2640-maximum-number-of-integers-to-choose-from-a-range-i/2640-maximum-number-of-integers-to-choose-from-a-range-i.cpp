class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>st;
        for(auto&i:banned){
            if(i<=n)st.insert(i);
        }
        int c=0,sm=0;
        for(int i=1;i<=n;++i){
            if(st.count(i)) continue;
            if(sm+i>maxSum)return c;
            ++c;
            sm+=i;
        }
        return c;
    }
};