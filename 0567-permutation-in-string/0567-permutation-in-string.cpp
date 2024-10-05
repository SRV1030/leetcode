class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        if(n1>n2) return false;
        sort(begin(s1),end(s1));
        for(int i=0;i<n2-n1+1;++i){
            string s=s2.substr(i,n1);
            sort(begin(s),end(s));
            if(s==s1) return true;
        }
        return false;
    }
};