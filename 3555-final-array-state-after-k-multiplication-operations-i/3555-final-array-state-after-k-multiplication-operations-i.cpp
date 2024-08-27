class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        for(int i=0;i<size(nums);++i)pq.push({nums[i],i});
        while(k--){
            auto x=pq.top();
            pq.pop();
            pq.push({x.first*multiplier,x.second});
        }
        while(!pq.empty()){
            auto x=pq.top();
            nums[x.second]=x.first;
            pq.pop();
        }
        return nums;
    }
};