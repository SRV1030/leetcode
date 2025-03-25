class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        vector<long long>end(skill.size());
        for(int i=0;i<mana.size();i++){
            long long t=0,mxd=0;
            for(int j=0;j<skill.size();j++){
                mxd=max(mxd,end[j]-t);
                t+=skill[j]*mana[i];
                end[j]=t;
            }
            for(auto&j:end)j+=mxd;
        }
        return end.back();
    }
};