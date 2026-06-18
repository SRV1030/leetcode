class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> lis;
        sort(envelopes.begin(), envelopes.end(), [](auto& a, auto& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        for(auto& pair : envelopes){
            auto itr = lower_bound(lis.begin(), lis.end(), pair[1]);
            if(itr == lis.end())
                lis.push_back(pair[1]);
            else if(*itr > pair[1])
                *itr = pair[1];
        }
        return lis.size();
    }
};