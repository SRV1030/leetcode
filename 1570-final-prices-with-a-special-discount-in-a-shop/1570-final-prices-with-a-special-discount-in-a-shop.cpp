class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        unordered_map<int,int>mp;
        for(int i=0;i<prices.size();++i){
            while(!st.empty() && prices[st.top()]>=prices[i]){
                mp[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<prices.size();++i) {
            if(mp.count(i))
                prices[i]-=prices[mp[i]];
        }
        return prices;
    }
};