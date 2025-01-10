class Solution {
public:
    string longestPalindrome(string s) {
        int mx=0,ind=0;
        for(int i=0;i<s.size();++i){
            int l=i,r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                l--;r++;
            }
            if(r-l-1>mx){
                mx=r-l-1;
                ind=l+1;
            }
            l=i,r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                l--;r++;
            }
            if(r-l-1>mx){
                mx=r-l-1;
                ind=l+1;
            }
        }
        return s.substr(ind,mx);
    }
};