class Solution {
public:
    vector<int> res;
    unordered_map<int,int>in,ot;
    unordered_map<int,deque<int>>gr;
    set<int>st;
    void dfs(int start){
        while(!gr[start].empty()){
            int nxt=gr[start].front();
            gr[start].pop_front();
            dfs(nxt);
        }
        res.push_back(start);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        for(auto&i:pairs){
            gr[i[0]].push_back(i[1]);
            in[i[1]]++;
            ot[i[0]]++;
        }
        int start=-1;
        for(auto&[i,j]:ot){
            if(ot[i]==in[i]+1){
                start = i;
                break;
            }
        }
        if(start==-1)start=pairs[0][0];
        vector<vector<int>> ans;
        dfs(start);
        reverse(res.begin(),res.end());
        for(int i=0;i<res.size()-1;++i)ans.push_back({res[i],res[i+1]});
        return ans;
    }
};