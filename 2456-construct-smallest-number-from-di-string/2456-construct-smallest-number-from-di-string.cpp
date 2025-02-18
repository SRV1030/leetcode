class Solution {
public:
    int n;
    string sm;
    string ans="";
    bool check(string sm, string pt){
        for(int i=0;i<pt.size();i++){
            if(pt[i]=='I' && sm[i]>sm[i+1]) return false;
            else if (pt[i]=='D' && sm[i]<sm[i+1]) return false;
        }
        return true;
    }
    void allPos(int i,string pt){
        if(i==n+1){
            if(check(sm,pt)){
                if(!ans.size() || (ans.size() && sm<ans)) ans=sm;
            }
            return;
        }
        for(int j=i;j<=n;++j){
            swap(sm[i],sm[j]);
            allPos(i+1,pt);
            swap(sm[i],sm[j]);
        }
    }
    string smallestNumber(string pt) {
        n = pt.size();
        for(int i=1;i<=n+1;++i)sm+=to_string(i);
        allPos(0,pt);
        return ans;
    }
};