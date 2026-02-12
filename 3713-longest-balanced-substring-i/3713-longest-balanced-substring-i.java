class Solution {
    public int longestBalanced(String s) {
        int result = 0;
        for(int index = 0; index < s.length(); ++index){
            int[] frequency = new int[26];
            int maxF = 0, count = 0, elements = 0;
            for(int next = index; next < s.length(); ++next){
                int fr = ++frequency[s.charAt(next) - 'a'];
                elements += (fr == 1 ? 1 : 0);
                if(fr > maxF){
                    maxF = fr;
                    count = 1;
                }
                else if(fr == maxF)
                    ++count;
                if(count == elements)
                    result = Math.max(result, next - index + 1);
            }
        }
        return result;
    }
}