class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx=0,ans=0,temp_ans=0;
        for(auto&i:nums){
            if(i>mx){
                mx=i;
                temp_ans=ans=0;
            }
            if (i==mx)temp_ans++;
            else temp_ans=0;
            ans=max(ans,temp_ans);
        }
        return ans;
    }
};