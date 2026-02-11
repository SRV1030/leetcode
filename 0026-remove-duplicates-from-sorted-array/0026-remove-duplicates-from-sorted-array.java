class Solution {
    public int removeDuplicates(int[] nums) {
        int prev = Integer.MIN_VALUE, lastIndex = -1;
        for(int index = 0; index < nums.length; ++index){
            if(prev == nums[index])
                continue;
            else{
                nums[++lastIndex] = nums[index];
                prev = nums[index];
            }
        }
        return lastIndex + 1;
    }
}