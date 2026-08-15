class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int size = tasks.size();
        for(int ind = 0; ind < size; ++ind){
            tasks[ind].push_back(ind);
        }
        sort(tasks.begin(), tasks.end());
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        vector<int> res;
        int time = 0;
        for(int ind = 0; ind < size;){
            while(ind < size && tasks[ind][0] <= time){
                minHeap.push({tasks[ind][1], tasks[ind][2]});
                ++ind;
            }
            if(minHeap.empty()){
                time = tasks[ind][0];
                continue;
            }
            auto[endTime, index] = minHeap.top();
            res.push_back(index);
            minHeap.pop();
            time += endTime;
        }
        while(!minHeap.empty()){
            auto[endTime, index] = minHeap.top();
            res.push_back(index);
            minHeap.pop();
        }
        return res;
    }
};