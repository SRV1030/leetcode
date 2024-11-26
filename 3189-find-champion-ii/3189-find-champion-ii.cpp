class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
       vector<int>indeg(n);
       for(auto&i:edges){
        ++indeg[i[1]];
       } 
       int c=0,ans=-1;
       for(int i=0;i<n;++i){
        if(!indeg[i]){
            if(c) return -1;
            ++c;
            ans=i;
        }
       }
       return ans;
    }
};