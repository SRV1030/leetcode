class Solution {
    class DSU{
        int size;
        vector<int> ranks, parents;
        vector<int> maxVal;
    public:
        DSU(vector<int> &num){
            size = num.size();
            ranks = vector<int>(size, 1);
            parents = vector<int>(size);
            iota(parents.begin(), parents.end(), 0);
            maxVal = num;
        }

        int find(int node){
            if( node == parents[node])
                return node;
            return parents[node] = find(parents[node]);
        }

        void unite(int node1, int node2){
            int p1 = find(node1), p2 = find(node2);
            if(p1 == p2)
                return;
            if(ranks[p1] < ranks[p2]){
                parents[p1] = p2;
                ranks[p2] += ranks[p1];
                maxVal[p2] = max(maxVal[p1], maxVal[p2]);
            }
            else{
                parents[p2] = p1;
                ranks[p1] += ranks[p2];
                maxVal[p1] = max(maxVal[p1], maxVal[p2]);
            }
        }

        int getMax(int node){
            return maxVal[find(node)];
        }
    };
public:
    vector<int> maxValue(vector<int>& nums) {
        DSU uf(nums);
        int size = nums.size();

        vector<int> prefMax(size), suffMin(size);

        prefMax[0] = nums[0];
        for (int ind = 1; ind < size; ++ind)
            prefMax[ind] = max(prefMax[ind - 1], nums[ind]);

        suffMin[size - 1] = nums[size - 1];
        for (int ind = size - 2; ind >= 0; --ind)
            suffMin[ind] = min(suffMin[ind + 1], nums[ind]);

        for (int ind = 0; ind < size - 1; ++ind){
            if(prefMax[ind] > suffMin[ind + 1])
                uf.unite(ind, ind + 1);
        }
        vector<int> result;
        for(int ind = 0; ind < size; ++ind)
            result.push_back(uf.getMax(ind));
        return result;
    }
};