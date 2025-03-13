class Solution {
public:
    bool canBeReducedByK(vector<int>& nums, vector<vector<int>>& queries,int k){
        int n = nums.size();
        vector<int>diffArray(n+1);
        for(int i=0;i<k;i++){
            diffArray[queries[i][0]]+=queries[i][2];
            diffArray[queries[i][1]+1]-=queries[i][2];
        }
        for(int i=1;i<diffArray.size();i++)diffArray[i]+=diffArray[i-1];
        for(int i=0;i<n;i++)
            if(diffArray[i]<nums[i]) return false;
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0, r = queries.size(), ans=-1;
        while(l<=r){
            int m=(l+r)/2;
            if(canBeReducedByK(nums,queries,m)){
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};