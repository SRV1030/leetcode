class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        auto by_desc = [](const auto &a,const auto &b){
            return a[1]>b[1];
        };
        for(int i=0;i<queries.size();++i)queries[i].push_back(i);
        sort(rooms.begin(),rooms.end(),by_desc);
        sort(queries.begin(),queries.end(),by_desc);
        set<int>ids;
        int i=0;
        vector<int> res(queries.size());
        for(auto&q:queries){
            for(;i<rooms.size() && rooms[i][1]>=q[1];++i)ids.insert(rooms[i][0]);
            auto it = ids.lower_bound(q[0]);
            auto id1 = it == ids.begin()?-1:*(prev(it));
            auto id2 = it == ids.end()?-1: *it;
            res[q[2]] = min(id1,id2)==-1?max(id1,id2): abs(q[0]-id1)<=abs(q[0]-id2)?id1:id2;
        }
        return res;
    }
};