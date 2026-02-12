class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Deque<Integer> stack = new ArrayDeque<Integer>();
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int index = nums2.length - 1; index >= 0; --index){
            while(!stack.isEmpty() && stack.peek() < nums2[index])
                stack.pop();
            map.put(nums2[index], stack.isEmpty() ? -1 : stack.peek());
            stack.push(nums2[index]);
        }

        int result[] = new int[nums1.length];
        for(int index = 0; index < nums1.length; ++index)
            result[index] = map.get(nums1[index]);
        return result;
    }
}