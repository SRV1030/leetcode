class Solution {
public:
    string s;
    set<string>st;
    int totalNumbers(vector<int>& digits,int mask=0) {
        if(s.size()==3){
            if(s[0]!='0' && (s[2]-'0')%2==0)
                return st.insert(s).second;
            return 0;
        } 
        int ans=0;
        for(int j=0;j<digits.size();j++){
            if(mask&(1<<(j+1))) continue;
            s+=to_string(digits[j]);
            ans+=totalNumbers(digits,mask|(1<<(j+1)));
            s.pop_back();
        }
        return ans;
    }
};