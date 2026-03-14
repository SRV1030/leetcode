class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses);
        vector<vector<int>> graph(numCourses);
        for(auto& course : prerequisites){
            graph[course[1]].push_back(course[0]);
            inDegree[course[0]]++;
        }
        queue<int> bfsQueue;
        for(int node = 0; node < numCourses; ++node){
            if(inDegree[node] == 0)
                bfsQueue.push(node);
        }
        int completedCourses = 0;
        while(!bfsQueue.empty()){
            int node = bfsQueue.front();
            bfsQueue.pop();
            ++completedCourses;
            for(auto& neighbour : graph[node]){
                inDegree[neighbour]--;
                if(!inDegree[neighbour])
                    bfsQueue.push(neighbour);
            }
        }
        return completedCourses == numCourses;
    }
};