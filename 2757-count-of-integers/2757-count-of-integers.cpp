class Solution {
public:
    int dp[23][2][2][401];
    int mod=1e9+7;
    int getSum(int i,bool lowLimit,bool highLimit,string num1, string num2,int sum){
        if(sum<0) return 0;
        if(i==num2.size()) return 1;
        int &ans = dp[i][lowLimit][highLimit][sum];
        if(ans!=-1) return ans;
        int lo =  lowLimit?num1[i]-'0':0;
        int hi = highLimit?num2[i]-'0':9;
        int count =0 ;
        for(int j=lo;j<=hi;j++){
            count = (count%mod + getSum(i+1,lowLimit && (j==lo),highLimit && (j==hi),num1,num2,sum-j)%mod)%mod;
        }
        return ans=count;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1,sizeof(dp));
        int lengthDiff = num2.size()-num1.size();
        num1 = string(lengthDiff,'0')+num1;
        int sum1 = getSum(0,1,1,num1,num2,max_sum),sum2=getSum(0,1,1,num1,num2,min_sum-1);
        return (sum1-sum2+mod)%mod;
    }
};