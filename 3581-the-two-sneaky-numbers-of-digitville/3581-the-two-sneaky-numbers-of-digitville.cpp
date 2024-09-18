class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& arr) {
        int n=arr.size()-2,xr1=0,xr2=0,xr=0;
        for(auto&i:arr)xr^=i;
        for(int i=0;i<n;++i)xr^=i;
        int mask = xr & ~(xr - 1);;
        for(auto&i:arr){
            if((mask&i)>0)xr1^=i;
            else xr2^=i;
        }
        for(int i=0;i<n;++i){
            if((mask&i)>0)xr1^=i;
            else xr2^=i;
        }
        return {xr1,xr2};
    }
};