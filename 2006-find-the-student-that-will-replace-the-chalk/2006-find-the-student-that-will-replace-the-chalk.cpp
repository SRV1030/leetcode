class Solution {
public:
    int chalkReplacer(vector<int>& c, int k) {
        long long sm = 0;
        for(int i=0;i<c.size();++i) {
            sm+=c[i];
            if(sm>k) return i;
        }
        k=k%sm;
        for(int i=0;i<c.size();++i){
            if(k<c[i]) return i;
            k-=c[i];
        }
        return 0;
    }
};