class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& height) {
        int size = height.size();
        vector<int> result(size);
        stack<int> prevHeight;
        for(int index = size - 1; index >= 0; --index){
            int count = 0;
            while(!prevHeight.empty() && height[index] > prevHeight.top()){
                ++count;
                prevHeight.pop();
            }
            if(!prevHeight.empty())
                ++count;
            result[index] = count;
            prevHeight.push(height[index]);
        }
        return result;
    }
};