class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& qrs) {
        vector<int> ans;
        unordered_map<int,int>f;
        unordered_map<int, int> mp;
        for (auto& i : qrs) {
            if (!f.count(i[0])) {
                f[i[0]] = i[1];
                mp[i[1]]++;
            } else {
                int prev = f[i[0]];
                mp[prev]--;
                if(mp[prev]==0)mp.erase(prev);
                f[i[0]] = i[1];
                mp[i[1]]++;
            }
            ans.push_back(mp.size());
        }
        return ans;
    }
};