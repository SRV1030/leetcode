class Solution {
public:
    int trap(vector<int>& h) {
        int l=0,r=h.size()-1,lmx=0,ans=0,rmx=0;
        while(l<=r){
            if(h[l]<=h[r]){
                if(lmx>h[l])ans+=lmx-h[l];
                else lmx=h[l];
                l++;
            }else{
                if(rmx>h[r])ans+=rmx-h[r];
                else rmx=h[r];
                r--;
            }
        }
        return ans;
    }
};