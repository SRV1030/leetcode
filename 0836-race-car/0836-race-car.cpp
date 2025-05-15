class Solution {
public:
    int racecar(int target) {
        queue<vector<int>> traversalSimulator;
        traversalSimulator.push({0, 1, 0}); // start / speed / steps;
        const int UPPER_LIMIT = 10004, LOWER_LIMIT = 1; 
        while(!traversalSimulator.empty()){
            vector<int> currentState = traversalSimulator.front();
            traversalSimulator.pop();
            int position = currentState[0], speed = currentState[1], steps = currentState[2];
            if(position == target) return steps;
            steps++;
            if(position + speed <= UPPER_LIMIT && position + speed >= LOWER_LIMIT)
                traversalSimulator.push({position + speed, speed * 2, steps});
            
            if(speed > 0 && (position + speed) > target)
                traversalSimulator.push({position, -1, steps});

            if(speed < 0 && (position + speed) < target)
                traversalSimulator.push({position, 1, steps});
            
        }
        return -1;
    }
};