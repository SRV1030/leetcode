class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> simulator;
        vector<int> maxWindow;
        for(int index = 0; index < nums.size(); ++ index){
            if(!simulator.empty() && index - k == simulator.front())
                simulator.pop_front();
            while(!simulator.empty() && nums[index] >= nums[simulator.back()])
                simulator.pop_back();
            simulator.push_back(index);
            if(index + 1 >= k)
                maxWindow.push_back(nums[simulator.front()]);
        }
        return maxWindow;
    }
};