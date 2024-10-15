class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps=0,bc=0;
        for(auto&i:s){
            if(i=='0')swaps+=bc;
            else ++bc;
        }
        return swaps;
    }
};