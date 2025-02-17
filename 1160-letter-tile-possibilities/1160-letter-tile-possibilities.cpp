class Solution {
public:
    unordered_map<char,int>mp;
    int c=0;
    void rec(){
        for(auto&[k,v]:mp){
            if(v>0){
                --v;
                ++c;
                rec();
                ++v;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        for(auto&i:tiles)mp[i]++;
        rec();
        return c;
    }
};