class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(begin(items),end(items));
        unordered_map<int,int>mp;
        set<int>st;
        int mx=-1;
        for(auto&i:items){
            mx=max(mx,i[1]);
            mp[i[0]]=mx;
            st.insert(i[0]);
        }
        vector<int> ans;
        for(auto&i:queries){
            auto it = st.lower_bound(i);
            if(*it==i){
                ans.push_back(mp[*it]);
                continue;
            }
            if(it!=st.begin()) {
                --it;
                ans.push_back(mp[*it]);
            }
            else ans.push_back(0);
        }
        return ans;
    }
};