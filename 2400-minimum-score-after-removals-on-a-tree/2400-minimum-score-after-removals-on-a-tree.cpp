class Solution {
    int numberOfNodes;
    vector<bool> visited;
    vector<pair<int, int>> parentChildEdges;
    vector<vector<int>> adjGraph;
    vector<vector<bool>> isParent;
    vector<int> childXors, nums, currentParents;
public:
    int dfs(int node){
        int xorVal = nums[node];
        visited[node] = true;

        for(auto& parent: currentParents)
            isParent[parent][node] = true;

        currentParents.push_back(node);

        for(auto& child : adjGraph[node]){
            if(!visited[child]){
                parentChildEdges.push_back({node, child});
                xorVal ^= dfs(child);
            }
        }
        currentParents.pop_back();
        return childXors[node] = xorVal;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        numberOfNodes = nums.size();
        this->nums = nums;
        visited = vector<bool>(numberOfNodes);
        isParent = vector<vector<bool>>(numberOfNodes, vector<bool>(numberOfNodes));
        adjGraph = vector<vector<int>>(numberOfNodes);
        childXors = vector<int>(numberOfNodes);

        for(auto& edge: edges){
            adjGraph[edge[0]].push_back(edge[1]);
            adjGraph[edge[1]].push_back(edge[0]);
        }

        int totalXor = 0;
        for(auto&num : nums)
            totalXor ^= num;

        dfs(0);

        int maxDiff = INT_MAX;

        for(int index = 0; index < parentChildEdges.size(); ++index){
            for(int nextIndex = index + 1; nextIndex < parentChildEdges.size(); ++nextIndex){
                int nodeA = parentChildEdges[index].second;
                int nodeB = parentChildEdges[nextIndex].second;
                
                int xorA = childXors[nodeA];
                int xorB = childXors[nodeB];
                int xorC = totalXor;

                if(isParent[nodeA][nodeB]){
                    xorC ^= xorA;
                    xorA ^= xorB;
                }
                else if (isParent[nodeB][nodeA]){
                    xorC ^= xorB;
                    xorB ^= xorA;
                }
                else{
                    xorC ^= xorA;
                    xorC ^= xorB;
                }

                maxDiff = min(maxDiff, max({xorA, xorB, xorC}) - min({xorA, xorB, xorC}));
            }
        }
        return maxDiff;
    }
};