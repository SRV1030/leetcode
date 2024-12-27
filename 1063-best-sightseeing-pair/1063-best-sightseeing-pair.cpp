class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int i=0,mxL=values[0],ans=0;
        for(int j=1;j<values.size();++j){
            int curR=values[j]-j;
            ans=max(ans,mxL+curR);
            mxL=max(mxL,values[j]+j);
        }
        return ans;
    }
};