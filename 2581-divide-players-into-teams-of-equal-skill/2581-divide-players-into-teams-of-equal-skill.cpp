class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=size(skill);
        long long ans =0,sm=-1;
        sort(begin(skill),end(skill));
        for(int i=0,j=n-1;i<j;++i,--j){
            long long csm=skill[i]+skill[j];
            if(sm<0)sm=csm;
            if(csm!=sm)return -1;
            ans+=skill[i]*skill[j];
        }
        return ans;
    }
};