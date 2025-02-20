class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>st(begin(nums),end(nums));
        int n=nums.size();
        string t="";
        for(int i=0;i<=n;++i){
            int x=n,msk=i;
            while(x--){
                if(msk&1)t+='1';
                else t+='0';
                msk>>=1;
            }
            if(!st.count(t)) return t;
            t="";
        }
        return "";
    }
};