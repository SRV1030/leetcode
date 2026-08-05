class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = position.size();
        vector<pair<int, int>> cars;
        for(int ind = 0; ind < size; ++ind)
            cars.push_back({position[ind], speed[ind]});
        sort(cars.begin(), cars.end());
        stack<double> st;
        for(auto& car : cars){
            double time = (target - car.first) / (double)car.second;
            while(!st.empty() && st.top() <= time)
                st.pop();
            st.push(time);
        }
        return st.size();
    }
};