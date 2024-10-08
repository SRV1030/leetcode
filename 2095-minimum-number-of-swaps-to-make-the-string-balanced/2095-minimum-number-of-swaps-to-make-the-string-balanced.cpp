class Solution {
public:
    int minSwaps(string s) {
        int c=0,ans=0;
        for(auto&i:s){
            if(i==']')++c;
            else --c;
            ans=max(ans,c);
        }
        return (ans+1)/2;
    }
};