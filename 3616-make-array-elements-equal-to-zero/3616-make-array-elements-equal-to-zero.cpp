class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        vector<int>pre(nums.size());
        pre[0]=nums[0];
        for(int i=1;i<size(nums);++i)pre[i]=nums[i]+pre[i-1];
        int vs=0;
        for(int i=0;i<size(nums);++i){
            if(nums[i]==0){
                int rs = pre[nums.size()-1]-pre[i];
                if(i==(nums.size()-1) && pre[i]==0)vs+=2;
                else if(pre[i]==rs) vs+=2;
                else if(pre[i]-1==rs || pre[i]+1==rs) ++vs;
            }
        }
        return vs;
    }
};