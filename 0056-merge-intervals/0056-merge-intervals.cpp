class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intv) {
        sort(intv.begin(),intv.end());
        vector<vector<int>> ans;
        ans.push_back(intv[0]);
        for(int i=1;i<size(intv);++i){
            if(ans.back()[1]>=intv[i][0])ans.back()[1]=max(ans.back()[1],intv[i][1]);
            else ans.push_back(intv[i]);
        }
        return ans;
    }
};