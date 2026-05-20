class Solution {
public:
    int trap(vector<int>& height) {
        int trappedWater = 0, sizeOfHeight = height.size();
        int leftMax = height[0], left = 0;
        int rightMax = height[sizeOfHeight - 1], right = sizeOfHeight - 1;
        while(left <= right){
            if(height[left] <= height[right]){
                if(leftMax > height[left])
                    trappedWater += leftMax - height[left];
                else
                    leftMax = height[left];
                left++;
            }
            else{
                if(rightMax > height[right])
                    trappedWater += rightMax - height[right];
                else
                    rightMax = height[right];
                right--;
            }
        }
        return trappedWater;
    }
};