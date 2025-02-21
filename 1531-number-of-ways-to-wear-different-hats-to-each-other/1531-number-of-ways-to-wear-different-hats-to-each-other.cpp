class Solution {
public:
    int mod = 1e9 + 7;
    int number_of_people;
    
    int findAllWays(int curr_hat, long long mask, vector<vector<int>>& people,vector<vector<int>>&dp) {
        if(mask==(1<<number_of_people)-1) return 1;
        if (curr_hat == people.size())
            return 0;
        
        if (dp[curr_hat][mask]!=-1) 
            return dp[curr_hat][mask];
        
        long long total_ways = 0;
        for (auto& person : people[curr_hat]) {
            if ((mask & (1LL << person)) == 0) {
                total_ways = (total_ways % mod +
                              findAllWays(curr_hat + 1, mask | (1LL << person), people,dp) % mod) % mod;
            }
        }
        total_ways = (total_ways % mod + findAllWays(curr_hat + 1, mask , people,dp) % mod) % mod;
        return dp[curr_hat][mask] = total_ways % mod;
    }

    int numberWays(vector<vector<int>>& hats) { 
        vector<vector<int>> people,temp_hats(41),dp(41,vector<int>(1<<11,-1));
        for(int i=0;i<hats.size();++i){
            for(auto&hat:hats[i])temp_hats[hat].push_back(i);
        }
        for(auto&hat:temp_hats){
            if(hat.size())people.push_back(hat);
        }
        number_of_people = hats.size();
        return findAllWays(0, 0, people,dp);
    }
};
