class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses);
        for(auto& course : prerequisites){
            graph[course[1]].push_back(course[0]);
            ++inDegree[course[0]];
        }
        queue<int> bfsQueue;
        for(int course = 0; course < numCourses; ++course)
            if(!inDegree[course])
                bfsQueue.push(course);
        vector<int> order;
        while(!bfsQueue.empty()){
            int front = bfsQueue.front();
            bfsQueue.pop();
            order.push_back(front);
            for(auto& course : graph[front]){
                --inDegree[course];
                if(!inDegree[course])
                    bfsQueue.push(course);
            }
        }
        return order.size() == numCourses ? order : vector<int>();
    }
};