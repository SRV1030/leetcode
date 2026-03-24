class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int count = 1;
        sort(coins.begin(), coins.end());
        for(auto& coin : coins){
            if(count < coin)
                return count;
            count += coin;
        }
        return count;
    }
};