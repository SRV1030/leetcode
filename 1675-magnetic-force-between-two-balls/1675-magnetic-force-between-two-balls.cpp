class Solution {
public:

    bool pos(vector<int>& p,int m,int dis){
        int c=0,cb=1;
        for(int i=1;i<size(p);++i){
            if(p[i]-p[c]>=dis){
                c=i;
                ++cb;
            }
            if(cb==m) return true;
        }
        return cb==m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int l=1,h=position[n-1]-position[0],mx=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(pos(position,m,mid)){
                mx=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return mx;
    }
};