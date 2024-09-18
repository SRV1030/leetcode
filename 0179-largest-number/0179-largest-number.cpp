class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(begin(nums),end(nums),[](int a,int b){
            string x=to_string(a),y=to_string(b);
            return x+y>y+x;
        });
        if(nums[0]==0)return "0";
        string ans="";
        for(auto&i:nums)ans+=to_string(i);
        return ans;
    }
};