class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int maxLeft = 0, maxRight = 0;
        for(int left = 0, right = height.size() - 1; left < right;){
            if(height[left] <= height[right]){
                maxArea = max(maxArea, height[left] * (right - left));
                ++left;
            }
            else{
                maxArea = max(maxArea, height[right] * (right - left));
                --right;
            }
        }
        return maxArea;
    }
};