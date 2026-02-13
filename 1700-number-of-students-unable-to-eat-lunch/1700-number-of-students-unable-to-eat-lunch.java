class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        Deque<Integer> stack = new ArrayDeque<>();
        Deque<Integer> queue = new ArrayDeque<>();
        
        for(int i = sandwiches.length - 1; i >= 0; i--)
            stack.push(sandwiches[i]);
            
        for(int student : students)
            queue.offerLast(student);

        while(!stack.isEmpty()){
            int initialSize = stack.size();
            int sandwich = stack.peek();
            for(int loop = queue.size(); loop > 0; --loop){
                int student = queue.pollFirst();
                if(student == sandwich){
                    stack.pop();
                    break;
                }
                queue.offerLast(student);
            }
            if(stack.size() == initialSize)
                return queue.size();
        }

        return 0;
    }
}