class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> serverQueue;

        priority_queue<tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>> taskQueue;

        for(int i = 0; i < servers.size(); ++i)
            serverQueue.push({servers[i], i});

        vector<int> result(tasks.size());

        for(int i = 0; i < tasks.size(); ++i){
            while(!taskQueue.empty()){
                auto [timeTaken, serverWt, serverIndex] = taskQueue.top();
                if(timeTaken <= i){
                    taskQueue.pop();
                    serverQueue.push({serverWt, serverIndex});
                } else break;
            }

            if(!serverQueue.empty()){
                auto [serverWt, serverIndex] = serverQueue.top();
                serverQueue.pop();
                result[i] = serverIndex;
                taskQueue.push({(long long)i + tasks[i], serverWt, serverIndex});
            } else {
                auto [timeTaken, serverWt, serverIndex] = taskQueue.top();
                taskQueue.pop();
                result[i] = serverIndex;
                taskQueue.push({timeTaken + tasks[i], serverWt, serverIndex});
            }
        }

        return result;
    }
};
