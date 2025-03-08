class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int mn=INT_MAX,wb=0,n=blocks.size();
        for(int i=0,j=0;j<n;++j){
            if(blocks[j]=='W')wb++;
            if(j-i+1==k){
                mn=min(mn,wb);
                if(blocks[i++]=='W')wb--;
            }
        }
        return mn;
    }
};