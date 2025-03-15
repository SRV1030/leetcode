class Solution {
public:
    bool isPossible(vector<int>& candies, long long k,int m){
        if(m==0) return true;
        long long c=0;
        for(auto&i:candies){
            c+=i/m;
            if(c>=k) return true;
        }
        return c>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long l=0,h=0,ans=0;
        for(auto&i:candies)h+=i;
        while(l<=h){
            long long m = (l+h)/2;
            if(isPossible(candies,k,m)){
                ans=m;
                l=m+1;
            }
            else h=m-1;
        }
        return ans;
    }
};