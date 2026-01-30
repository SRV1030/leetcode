class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> fo(26, -1), lo(26, -1);
        for(int index = 0; index < s.size(); ++index){
            int ci = s[index] - 'a';
            if(fo[ci] == -1)
                fo[ci] = index;
            lo[ci] = index;
        }
        vector<vector<int>> fl;
        for(int ind = 0; ind < 26; ++ind){
            if(fo[ind] != -1)
                fl.push_back({fo[ind], lo[ind]});
        }
        sort(fl.begin(), fl.end());
        vector<vector<int>> merged = {fl[0]};
        for(int index = 1; index < fl.size(); ++index){
            if(merged.back()[1] > fl[index][0])
                merged.back()[1] = max(merged.back()[1], fl[index][1]);
            else
                merged.push_back(fl[index]);
        }
        vector<int> res;
        for(auto& merge : merged)
            res.push_back(merge[1] - merge[0] + 1);
        return res;
    }
};