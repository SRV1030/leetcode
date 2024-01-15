class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>wmp,lmp;
        for(auto&i:matches)wmp[i[0]]++,lmp[i[1]]++;
        vector<vector<int>> ans(2);
        for(auto&[k,v]:wmp)
            if(!lmp.count(k))ans[0].push_back(k);
        for(auto&[k,v]:lmp)
            if(v==1)ans[1].push_back(k);
        return ans;
    }
};