class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int size = cost.size();
        vector<int> answer(size, -1);
        vector<vector<int>> costInd;
        for (int i = 0; i < size; i++)
            costInd.push_back({cost[i], i});
        sort(costInd.begin(), costInd.end());
        for (auto& i : costInd) {
            int index = i[1], value = i[0];
            if (answer[index] != -1)continue;
            for (; index < size && answer[index]==-1; index++)
                answer[index] = value;
        }
        return answer;
    }
};