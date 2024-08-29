class Solution {
public:
    int n;
    vector<vector<string>> dp; 
    string tsp(vector<string>& words,vector<vector<int>>& olp,int pos,int vis){
        if(vis == (1<<n)-1) return "";
        if(dp[pos][vis].length()) return dp[pos][vis];
        int mn=1e9;
        string ans,temp;
        for(int i=0;i<n;++i){
            if((vis&(1<<i))==0){
                temp = words[i].substr(olp[pos][i]) + tsp(words,olp,i,(vis|(1<<i)));
                if(temp.size()<mn){
                    mn=temp.size();
                    ans=temp;
                }
            }
        }
        return dp[pos][vis] = ans;
    }
    string shortestSuperstring(vector<string>& words) {
        n = words.size();
        dp = vector<vector<string>>(n+1,vector<string>((1<<n)+1,""));
        vector<vector<int>> olp(n,vector<int>(n,0));
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j){
                if(i==j)olp[i][j]=words[i].size();
                else{
                    int k=min(words[i].size(),words[j].size());
                    for(;k>=0;--k){
                        //finding overlap.
                        if(words[i].substr(words[i].size()-k) == words[j].substr(0,k)){
                            olp[i][j]=k;
                            break;
                        }
                    }
                }
            }
        

        int mn=1e9;
        string ans,temp;
        for(int i=0;i<n;++i){
            int vis = 1<<i;
            temp = words[i] + tsp(words,olp,i,vis);
            if(temp.size()<mn){
                mn=temp.size();
                ans=temp;
            }
        }

        return ans;
    }
};