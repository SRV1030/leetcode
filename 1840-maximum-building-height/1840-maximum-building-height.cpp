class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        int size = restrictions.size();
        for (int ind = 1; ind < size; ++ind) {
            int prevId = restrictions[ind - 1][0], prevHt = restrictions[ind - 1][1];
            restrictions[ind][1] = min(restrictions[ind][1], prevHt + restrictions[ind][0] - prevId);
        }
        for (int ind = size - 2; ind >= 0; --ind) {
            int prevId = restrictions[ind + 1][0], prevHt = restrictions[ind + 1][1];
            restrictions[ind][1] = min(restrictions[ind][1], prevHt + prevId - restrictions[ind][0]);
        }
        int mx = 0;
        for (int ind = 1; ind < size; ++ind){
            int prevId = restrictions[ind - 1][0], prevHt = restrictions[ind - 1][1];
            int curId = restrictions[ind][0], curHt = restrictions[ind][1];
            mx = max(mx, max(prevHt, curHt) + ((curId - prevId) - abs(prevHt - curHt)) / 2 );
        }
        auto& lastRes = restrictions.back();
        mx = max(mx, lastRes[1] + (n - lastRes[0]));
        return mx;
    }
};