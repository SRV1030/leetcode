class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        for(int left = 0, right = height.size() - 1; left < right;){
            if(height[left] <= height[right])
                area = max(area, height[left] * (right - left++));
            else
                area = max(area, height[right] * (right-- - left));
        }
        return area;
    }
};