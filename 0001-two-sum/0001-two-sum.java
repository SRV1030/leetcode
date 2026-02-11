class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int index = 0; index < nums.length; ++index){
            int key = target - nums[index];
            if(map.containsKey(key)){
                int prevIndex = map.get(key);
                int[] result = {prevIndex, index};
                return result;
            }
            map.put(nums[index], index);
        }
        return null;
    }
}