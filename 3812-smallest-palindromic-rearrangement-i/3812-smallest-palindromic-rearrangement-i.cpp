class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>frq(26);
        char ch = '$';
        string ans(s.size(),'a');
        for(auto&i:s)frq[i-'a']++;
        int l=0,h=s.size()-1;
        for(int i=0;i<26;i++){
            if(frq[i]){
                if(frq[i]%2){
                    ch='a'+i;
                }
                while(frq[i]>1){
                    ans[l++]='a'+i;
                    ans[h--]='a'+i;
                    frq[i]-=2;
                }
            }
        }
        if(l==h)ans[l]=ch;
        return ans;
    }
};