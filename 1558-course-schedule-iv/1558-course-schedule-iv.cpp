class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int>gr[n];
        vector<int>inD(n);
        vector<bool> ans;
        for(auto&i:prerequisites){
            gr[i[0]].push_back(i[1]);
            inD[i[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)if(!inD[i])q.push(i);
        unordered_map<int,set<int>>st;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            for(auto&j:gr[i]){
                st[j].insert(i);
                for(auto&p:st[i])st[j].insert(p);
                --inD[j];
                if(!inD[j])q.push(j);
            }
        }
        for(auto&q:queries)ans.push_back(st[q[1]].count(q[0]));
        return ans;
    }
};