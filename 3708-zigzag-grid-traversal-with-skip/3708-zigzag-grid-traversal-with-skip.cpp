class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& g) {
        int pr=0,r=g.size(),c=g[0].size();
        vector<int> ans;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;++j){
                if(pr%2==0)
                    ans.push_back(g[i][(i%2?c-j-1:j)]);
                ++pr;
            }
        }
        return ans;   
    }
};