class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if(nums1.empty() || nums2.empty() || k == 0) return res;

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

        for(int i = 0; i < min(k, (int)nums1.size()); i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while(!pq.empty() && res.size() < k) {
            auto [sum, i, j] = pq.top(); 
            pq.pop();

            res.push_back({nums1[i], nums2[j]});

            if(j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return res;
    }
};
