class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int res=0,mx=0;
        priority_queue<pair<int,int>>pq;
        sort(begin(events),end(events));
        for(auto&e:events){
            while(!pq.empty() && -pq.top().first<e[0]){
                mx=max(mx,pq.top().second);
                pq.pop();
            }
            res=max(res,mx+e[2]);
            pq.push({-e[1],e[2]});
        }
        return res;
    }
};