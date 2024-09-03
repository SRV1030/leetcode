class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        for(int j=0;j<k;++j){
            ans=0;
            for(auto&i:s){
                int t = i-(j==0?('a'-1):'0');
                while(t){
                    ans+=t%10;
                    t/=10;
                }
            }
            s=to_string(ans);
        }
        return ans;
    }
};