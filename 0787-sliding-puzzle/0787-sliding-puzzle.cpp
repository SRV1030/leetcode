class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string tg="123450";
        string st="";
        for(auto&i:board)
            for(auto&j:i)st+=to_string(j);
        queue<string>q;
        unordered_set<string>vis;
        q.push(st);
        vis.insert(st);
        int res=0;
        vector<vector<int>>dir={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string cur=q.front();
                q.pop();
                if(cur==tg)return res;
                int zeroInd = cur.find("0");
                for(auto&i:dir[zeroInd]){
                    swap(cur[zeroInd],cur[i]);
                    if(!vis.count(cur)){
                        vis.insert(cur);
                        q.push(cur);
                    }
                    swap(cur[zeroInd],cur[i]);
                }
            }
            res++;
        }
        return -1;
    }
};