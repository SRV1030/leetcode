class Solution {
public:
    class UnionFind{
        vector<int> parent,rank;
        int numberOfNodes, numberOfParents;
    public:
        UnionFind(int _numberOfNodes){
            numberOfNodes = _numberOfNodes;
            numberOfParents = _numberOfNodes;
            parent.resize(numberOfNodes);
            rank.resize(numberOfNodes, 1);
            iota(parent.begin(), parent.end(), 0);
        }

        int getParent(int child){
            if(child != parent[child])
                return parent[child] = getParent(parent[child]);
            return child;
        }

        void unite(int node1,int node2){
            int parent1 = getParent(node1), parent2 = getParent(node2);
            if(parent1 != parent2){
                if(rank[parent1] < rank[parent2]){
                    parent[parent1] = parent2;
                    rank[parent2] += rank[parent1];
                }
                else{
                   parent[parent2] = parent1;
                   rank[parent1] += rank[parent2]; 
                }
                --numberOfParents;
            }
        }

        int getGroupsCount(){
            return numberOfParents;
        }
    };

    bool isConnected(string word1, string word2){
        int differentAtIndex = 0;
        for(int index = 0; index < word1.size(); index++)
            differentAtIndex+= (word1[index] != word2[index]);
        return differentAtIndex == 0 || differentAtIndex == 2;
    }

    int numSimilarGroups(vector<string>& strs) {
        UnionFind unionFind(strs.size());
        for(int index1 = 0; index1 < strs.size(); index1++)
            for(int index2 = index1 + 1; index2 < strs.size(); index2++){
                if(isConnected(strs[index1], strs[index2])){
                    unionFind.unite(index1, index2);
                }
            }
        return unionFind.getGroupsCount();
    }
};