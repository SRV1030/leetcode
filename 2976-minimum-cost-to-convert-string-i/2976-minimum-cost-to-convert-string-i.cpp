class Solution {
    int distance[26][26];
public:
    void floydW(vector<char>& original, vector<char>& changed, vector<int>& cost){
        for(int row = 0; row < 26; ++row){
            fill(distance[row], distance[row] + 26, INT_MAX);
            distance[row][row] = 0;
        }

        for(int index = 0; index < original.size(); ++index){
            int row = original[index] - 'a';
            int col = changed[index] - 'a';
            distance[row][col] = min(distance[row][col], cost[index]);
        }

        for(int sup = 0; sup < 26; ++sup){
            for(int row = 0; row < 26; ++row){
                for(int col = 0; col < 26; ++col){
                    if(distance[row][sup] != INT_MAX && distance[sup][col] != INT_MAX)
                        distance[row][col] = min(distance[row][col], distance[row][sup] + distance[sup][col]);
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        floydW(original, changed, cost);
        long long costs = 0;
        for(int index = 0; index < source.size(); ++index){
            int row = source[index] - 'a';
            int col = target[index] - 'a';
            if(distance[row][col] == INT_MAX)
                return -1;
            costs += distance[row][col];
        }

        return costs;
    }
};