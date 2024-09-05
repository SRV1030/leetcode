class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        long sm = 0;
        for(auto&i:rolls)sm+=i;
        long sn = (n+rolls.size())*mean-sm;
        if(sn<n || sn>6*n) return {};
        vector<int> ans(n,sn/n);
        int md = sn%n;
        for(int i=0;i<md;++i)++ans[i];
        return ans;
    }
};