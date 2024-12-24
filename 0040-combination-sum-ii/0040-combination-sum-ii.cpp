class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& cd, int tg,int i,vector<int>t){
        if(tg==0){
            ans.push_back(t);
            return;
        }
        if(tg<0) return;
        for(int j=i;j<size(cd);++j){
            if(j!=i && cd[j]==cd[j-1]) continue;
            t.push_back(cd[j]);
            solve(cd,tg-cd[j],j+1,t);
            t.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates),end(candidates));
        solve(candidates,target,0,{});
        return ans;
    }
};