class Solution {
    public int residuePrefixes(String s) {
        Set<Character> set = new HashSet<>();
        char[] arr = s.toCharArray();
        int count = 0;
        for(int index = 0; index < arr.length; ++index){
            set.add(arr[index]);
            if(set.size() == (index + 1) % 3)
                ++count;
        }
        return count;
    }
}