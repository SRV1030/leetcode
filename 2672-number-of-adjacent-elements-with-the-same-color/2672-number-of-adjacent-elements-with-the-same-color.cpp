class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> color(n);
        int nbs = 0;
        vector<int> result;
        for(auto& query : queries){
            if(color[query[0]]){
                if(query[0] - 1 >= 0 && color[query[0] - 1] == color[query[0]])
                    --nbs;
                if(query[0] + 1 < n && color[query[0] + 1] == color[query[0]])
                    --nbs;
            }
            color[query[0]] = query[1];
            if(color[query[0]]){
                if(query[0] - 1 >= 0 && color[query[0] - 1] == color[query[0]])
                    ++nbs;
                if(query[0] + 1 < n && color[query[0] + 1] == color[query[0]])
                    ++nbs;
            }
            result.push_back(nbs);
        }
        return result;
    }
};