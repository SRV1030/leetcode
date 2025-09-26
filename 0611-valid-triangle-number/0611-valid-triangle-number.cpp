class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int triangles = 0;
        for(int index = nums.size() - 1; index > 0; index--){
            int left = 0, right = index - 1;
            while(left < right){
                if(nums[left] + nums[right] > nums[index]){
                    triangles += (right - left);
                    --right;
                }
                else ++left;
            }
        }
        return triangles;
    }
};