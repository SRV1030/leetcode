class Solution {
public:
    vector<int>parentChild[100001];
    int mx = 1;
    int dfs(string &s,int parent){
        if(parentChild[parent].empty()) return 1;
        int path1=0,path2=0;
        for(auto&child:parentChild[parent]){
            int tempMx = dfs(s,child);
            mx = max(mx,tempMx);
            if(s[child]==s[parent]) continue;
            if(tempMx>path1){
                path2=path1;
                path1=tempMx;
            }
            else path2=max(path2,tempMx);
        }
        int pathSum = path1+path2+1;
        mx=max(mx,pathSum);
        return 1+path1;
    }
    int longestPath(vector<int>& parent, string s) {
        for(int i=1;i<parent.size();i++)parentChild[parent[i]].push_back(i);
        dfs(s,0);
        return mx;
    }
};