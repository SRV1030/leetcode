class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0,c=0;
        for(auto&i:allowed) mask|=(1<<(i-'a'));
        for(auto&i:words){
            int f=0;
            for(auto&j:i){
                if((mask & (1<<(j-'a')))==0) f=1;
            }
            if(!f) ++c;
        }
        return c;
    }
};