class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inDegree(numCourses);
        vector<vector<int>>gr(numCourses);
        for(auto&i:prerequisites){
            inDegree[i[0]]++;
            gr[i[1]].push_back(i[0]);
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
            if(inDegree[i]==0)q.push(i);
        int c=0;

        while(!q.empty()){
            int cur=q.front();
            ++c;
            q.pop();
            for(auto&nb:gr[cur]){
                if(--inDegree[nb]==0)q.push(nb);
            }
        }
        return c==numCourses;
    }
};