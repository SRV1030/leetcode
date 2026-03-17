class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int size = nums.size();
        vector<long long> absArr;
        for(auto& num : nums)
            absArr.push_back(abs(1ll * num));
        sort(absArr.begin(), absArr.end());
        long long beauty = 0;
        for(int cur = 0, nxt = 1; cur < size; ++cur){
            while(nxt < size && absArr[nxt] <= 2 * absArr[cur])
                ++nxt;
            beauty += (nxt - cur - 1);
        }
        return beauty;
    }
};