class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>ans(code.size());
        if(!k) return ans;
        int s=1,e=k,sm=0;
        if(k<0){
            s=code.size()-abs(k);
            e=code.size()-1;
        }
        for(int i=s;i<=e;++i)sm+=code[i];
        for(int i=0;i<code.size();++i){
            ans[i]=sm;
            sm-=code[s%code.size()];
            sm+=code[(e+1)%code.size()];
            s++;
            e++;
        }
        return ans;
    }
};