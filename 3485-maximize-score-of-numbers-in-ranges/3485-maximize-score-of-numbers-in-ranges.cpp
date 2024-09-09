class Solution {
public:
    bool check(long md,vector<int>& start, int d){
        long cur = start[0];
        for(int i=1;i<start.size();++i){
            long next = max(cur+md,(long)start[i]);
            if(next>start[i]+d) return false;
            cur = next;
        }
        return true;
    } 
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end());
        long ans=0,n=(int)start.size(),l=0,h=start[n-1]-l+d;
        while(l<=h){
            long md = (l+h)/2;
            if(check(md,start,d)){
                ans=md;
                l=md+1;
            }
            else h=md-1;
        }
        return ans;
    }
};