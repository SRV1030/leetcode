class Solution {
    public String reverseWords(String s) {
        String[] collection = s.trim().split("\\s+");
        StringBuilder resultBuilder = new StringBuilder(); 
        for(int index =  collection.length - 1; index >= 0; --index){
            resultBuilder.append(collection[index]).append(" ");
        }
        return resultBuilder.toString().trim();
    }
}