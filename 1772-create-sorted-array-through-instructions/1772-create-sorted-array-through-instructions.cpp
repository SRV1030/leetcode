class Solution {
public:
    const int UPPER_LIMIT = 100001;
    const int MOD = 1e9 + 7;
    class FenwickTree{
        vector<int> tree;
        int treeSize;
    public:
        FenwickTree(int _treeSize){
            treeSize = _treeSize;
            tree.resize(treeSize);
        }

        void update(int index,int value){
            for(; index < treeSize; index += (index & (-index)))
                tree[index]+=value;
        }

        int query(int index){
            int value = 0;
            for(; index; index -= (index & (-index)))
                value += tree[index];
            return value;
        }
    };
    int createSortedArray(vector<int>& instructions) {
        FenwickTree tree(UPPER_LIMIT);
        int totalCost = 0;
        for(int insrtuctionIndex = 0; insrtuctionIndex < instructions.size(); insrtuctionIndex++){
            int numberOfStrictlyLessElements = tree.query(instructions[insrtuctionIndex] - 1);
            int numberOfStrictlyGreaterElements = insrtuctionIndex - tree.query(instructions[insrtuctionIndex]);
            totalCost = (totalCost + min(numberOfStrictlyLessElements, numberOfStrictlyGreaterElements)) % MOD;
            tree.update(instructions[insrtuctionIndex], 1);
        }
        return totalCost;
    }
};