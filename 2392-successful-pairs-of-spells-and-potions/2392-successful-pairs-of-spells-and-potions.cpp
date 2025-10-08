class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> result;

        for(auto& spell : spells){
            int low = 0, high = size(potions);
            while(low < high){
                int mid = (low + high) / 2;
                if(1ll * potions[mid] * spell >= success)
                    high = mid;
                else
                    low = mid + 1;
            }
            result.push_back(potions.size() - low);
        }
        return result;
    }
};