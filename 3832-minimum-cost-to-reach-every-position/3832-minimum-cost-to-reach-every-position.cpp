class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int size = cost.size();
        vector<int> answer(size);
        int minCost=cost[0];
        for (int i = 0; i < size; i++){
            minCost=min(minCost,cost[i]);
            answer[i]=minCost;
        }
        return answer;
    }
};