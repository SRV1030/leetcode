class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int md=-1;
        vector<int>flat;
        for(auto&i:grid)
            for(auto&j:i){
                if(md!=-1 && md!=(j%x)) return -1;
                md=j%x;
                flat.push_back(j);
            }
        sort(flat.begin(),flat.end());
        int m=flat[(flat.size())/2];
        int ops=0;
        for(auto&i:flat)ops+=abs(i-m)/x;
        return ops;
    }
};