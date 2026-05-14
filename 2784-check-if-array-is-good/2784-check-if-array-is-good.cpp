class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=*max_element(begin(nums),end(nums));
        if(n+1!=size(nums)) return false;
        vector<int>f(n+1);
        for(auto&i:nums){
            if(f[i]){
                if(i!=n)return false;
                if(i==n && f[i]>2) return false;
            }
            ++f[i];
        }
        return f[n]==2;
    }
};