class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> fr1, fr2;
        unordered_set<int> keys;
        for(auto& num : nums1){
            fr1[num]++;
            keys.insert(num);
        }
        for(auto& num : nums2){
            fr2[num]++;
            keys.insert(num);
        }
        int cost = 0;
        for(auto&key : keys){
            int sum = fr1[key] + fr2[key];
            if(sum % 2)
                return -1;
            if(fr1[key] == fr2[key])
                continue;
            cost += abs(fr1[key] - fr2[key]);
        }
        return cost / 4;
    }
};