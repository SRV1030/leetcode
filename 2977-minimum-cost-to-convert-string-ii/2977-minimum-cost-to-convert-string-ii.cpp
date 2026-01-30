class Solution {
    unordered_map<string, int> mp;
    vector<vector<long long>> distance;
    vector<long long> memo;
    int size;
    const long long INF = 1e18;
public:
    long long solve(int index, string& source, string& target){
        if(index >= size)
            return 0;
        long long &res = memo[index];
        if(res == -1){
            res = INF;
            if(source[index] == target[index])
                res = solve(index + 1, source, target);
            
            for(auto&[src, u] : mp){
                int len = src.size();
                if((index + len > size) || source.compare(index, len, src) != 0)
                    continue;
                for(auto&[dest, v] : mp){
                    if(dest.size() != len || target.compare(index, len, dest) != 0 || distance[u][v] == INF)
                        continue;
                    res = min(res, distance[u][v] + solve(index + len, source, target));
                }
            }
        }
        return res;
    }
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        size = source.size();
        int count = 0, vSize = original.size();
        memo = vector<long long>(size, -1);
        for(int index = 0; index < vSize; ++index){
            if(!mp.count(original[index]))
                mp[original[index]] = count++;
            if(!mp.count(changed[index]))
                mp[changed[index]] = count++;   
        }

        distance = vector<vector<long long>> (count, vector<long long> (count, INF));

        for(int index = 0; index < vSize; ++index){
            int u = mp[original[index]];
            int v = mp[changed[index]];
            distance[u][v] = min(distance[u][v], 1ll * cost[index]);
        }

        for(int sup = 0;  sup < count; ++sup){
            for(int u = 0; u < count; ++u){
                for(int v = 0; v < count; ++v){
                    if(distance[u][sup] != INF && distance[sup][v] != INF)
                        distance[u][v] = min(distance[u][v], distance[u][sup] + distance[sup][v]);
                }
            }
        }
        long long minDis = solve(0, source, target);
        return minDis >= INF ? -1 : minDis;

    }
};