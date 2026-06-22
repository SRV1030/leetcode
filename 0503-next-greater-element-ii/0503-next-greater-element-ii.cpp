class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int sizeOfNums = nums.size();
        stack<int> greaterElementStack;
        for(int index = sizeOfNums - 1; index >= 0; index--) 
            greaterElementStack.push(nums[index]);
        vector<int> nextGreaterElementList;
        for(int index = sizeOfNums - 1; index >= 0; index--){
            while(!greaterElementStack.empty() && nums[index] >= greaterElementStack.top())
                greaterElementStack.pop();
            int nextGreaterElement = greaterElementStack.empty() ? -1 : greaterElementStack.top();
            nextGreaterElementList.insert(nextGreaterElementList.begin(), nextGreaterElement);
            greaterElementStack.push(nums[index]);
        }
        return nextGreaterElementList;
    }
};