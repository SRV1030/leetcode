class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long mxs = 0,nc=0,mn=INT_MAX;
        for(auto&i:matrix){
            for(auto&j:i){
                long long x=abs(j);
                mxs+=x;
                mn=min(mn,x);
                if(j<0)++nc;
            }
        }
        return nc%2?mxs-2*mn:mxs;
    }
};