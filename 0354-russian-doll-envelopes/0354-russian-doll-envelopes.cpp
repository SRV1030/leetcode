class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> lis;
        sort(envelopes.begin(), envelopes.end(), [&] (auto& a, auto& b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        for(auto& doll : envelopes){
            auto itr = lower_bound(lis.begin(), lis.end(), doll[1]);
            if(itr != lis.end()){
                *itr = doll[1];
            }
            else
                lis.push_back(doll[1]);
        }
        return lis.size();
    }
};