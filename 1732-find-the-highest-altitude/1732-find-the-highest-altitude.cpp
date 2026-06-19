class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0, mx = 0;
        for(auto& ga : gain){
            curr += ga;
            mx = max(mx, curr);
        }
        return mx;
    }
};