class Solution {
public:
    
    int numberOfBeams(vector<string>& b) {
        int pv = 0, ans = 0;
        for(auto&i:b){
            int c = 0;
            for(auto&j:i)c+= j== '1';
            if(c){
                ans+=pv*c;
                pv=c;
            }
        }
        return ans;
    }
};