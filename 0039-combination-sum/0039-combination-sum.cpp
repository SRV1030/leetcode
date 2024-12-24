class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& cd, int tg,int i,vector<int>t){
        if(tg==0){
            ans.push_back(t);
            return;
        }
        if(tg<0 || i==size(cd)) return;
        solve(cd,tg,i+1,t);
        t.push_back(cd[i]);
        solve(cd,tg-cd[i],i,t);
        t.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates,target,0,{});
        return ans;
    }
};