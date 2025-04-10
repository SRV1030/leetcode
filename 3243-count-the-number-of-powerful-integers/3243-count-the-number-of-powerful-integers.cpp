class Solution {
public:
    long long dp[17][2];
    long long getCount(int index,bool tight,int limit,string suffix,string uBound){
        if(index == uBound.size()) return 1;
        auto &ans=dp[index][tight];
        if(ans!=-1) return ans;
        ans = 0;
        int lo = 0,hi = tight?min(limit,uBound[index]-'0'):limit;
        int suffix_index = uBound.size() - suffix.size();
        if(index>=suffix_index){
            lo = suffix[index - suffix_index] - '0';
            hi  = min(lo,hi);
        }
        for(int i=lo;i<=hi;i++)ans+=getCount(index+1,tight && (i==uBound[index]-'0'),limit,suffix,uBound);
        return ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startStr = to_string(start-1),finishStr = to_string(finish);
        long long startCount = 0,finishCount = 0;
        if(startStr.size()>=s.size()){
            memset(dp,-1,sizeof(dp));
            startCount = getCount(0,1,limit,s,startStr);
        }  
        if(finishStr.size()>=s.size()){
            memset(dp,-1,sizeof(dp));
            finishCount = getCount(0,1,limit,s,finishStr);
        }
        return finishCount - startCount;
    }
};