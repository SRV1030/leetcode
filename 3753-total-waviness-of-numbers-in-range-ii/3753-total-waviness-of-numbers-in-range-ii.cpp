class Solution {
    using ll = long long;
    struct Node{
        ll count; //count of valid numbers
        ll sum; //sum of wavewiness so far
    };
    Node memo[17][2][3][11][11];
    string str;
public:
    Node dfs(int ind, bool tight, int state, int last1, int last2){
        if(ind == str.size())
            return {1, 0};
        Node& res = memo[ind][tight][state][last1][last2];
        if(res.count == -1){
            res = {0, 0};
            int limit = tight ? str[ind] - '0' : 9;
            for(int dg = 0; dg <= limit; ++dg){
                bool nTight = tight && dg == limit;
                Node child;
                if(state == 0){
                    if(dg == 0)
                        child = dfs(ind + 1, nTight, 0, 10, 10);
                    else
                        child = dfs(ind + 1, nTight, 1, dg, 10);
                    res.count += child.count;
                    res.sum += child.sum;
                }
                else if(state == 1){
                    child = dfs(ind + 1, nTight, 2, dg, last1);
                    res.count += child.count;
                    res.sum += child.sum;
                }
                else{
                    int wave = last1 < min(dg, last2) || last1 > max(dg, last2);
                    child = dfs(ind + 1, nTight, 2, dg, last1);
                    res.count += child.count;
                    res.sum += child.sum + wave * child.count;
                }
            }
        }
        return res;
    }
    ll solve(ll num){
        str = to_string(num);
        memset(memo, -1, sizeof(memo));
        return dfs(0, 1, 0, 10, 10).sum;
    }
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};