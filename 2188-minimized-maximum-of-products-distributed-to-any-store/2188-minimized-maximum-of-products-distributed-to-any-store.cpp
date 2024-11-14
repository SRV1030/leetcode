class Solution {
public:

    bool isPoss(int n, vector<int>& qs,int k){
        if(!k) return true;
        int c=0;
        for(auto&i:qs){
            c+=(i/k)+((i%k)!=0);
            if(c>n) return false;
        }
        return c<=n;
    }
    int minimizedMaximum(int n, vector<int>& qs) {
        int l=1,h=*max_element(qs.begin(),qs.end()),ans=0;
        if(n==1) return h;
        if(qs.size()==1) return h;
        while(l<=h){
            int m = (l+h)>>1;
            if(isPoss(n,qs,m)){
                ans = m;
                h = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};