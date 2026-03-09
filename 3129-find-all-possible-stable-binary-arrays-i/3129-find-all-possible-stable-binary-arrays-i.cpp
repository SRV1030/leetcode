class Solution {
public:
    // int t[201][201][3][201];
    vector<vector<vector<vector<int>>>> t;

    int solve(int z, int o, int prev, int cnt, int l){
        if(z == 0 && o == 0)return 1;

        if(t[z][o][prev][cnt] != -1)return t[z][o][prev][cnt];
        // cout << "h";

        int ch1 = 0, ch2 = 0;
        if(prev == 0 || prev == -1){
            if(z > 0 && cnt < l){
                ch1 = solve(z-1, o, 0, cnt+1, l);
            }
            if(o > 0)ch2 = solve(z, o-1, 1, 1, l);
        }
        else if(prev == 1 || prev == -1){
            if(o > 0 && cnt < l){
                ch1 = solve(z, o-1, 1, cnt+1, l);
            }
            if(z > 0) ch2 = solve(z-1, o, 0, 1, l);
        }
        

        return t[z][o][prev][cnt] = (ch1 + ch2) % 1000000007;
    }
    int numberOfStableArrays(int z, int o, int l) {
        // memset(t, -1, sizeof(t));
        t = vector<vector<vector<vector<int>>>>(
            z + 1, vector<vector<vector<int>>>(
                o + 1, vector<vector<int>>(
                    2, vector<int>(l + 1, -1)
                )
            )
        );
        // vector<int> v(z + o, -1);
        return (solve(z - 1, o, 0, 1, l) + solve(z, o - 1, 1, 1, l)) % 1000000007;
    }
};