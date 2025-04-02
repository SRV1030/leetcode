class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long mx=0,n=nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++)mx=max(mx,(long long)(nums[i]-nums[j])*(long long)nums[k]);
            }
        }
        return mx;
    }
};