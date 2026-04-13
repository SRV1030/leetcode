class NumArray {
    class SegmentTree{
        vector<int> tree;
        int size;
    public:
        SegmentTree(vector<int> &nums){
            size = nums.size();
            tree = vector<int>(4 * size);
            build(0, size - 1, 0, nums);
        }

        int build(int left, int right, int node, vector<int> &nums){
            if(left == right){
                tree[node] = nums[left]; 
            }
            else{
                int mid = (left + right) / 2;
                int lSum = build(left, mid, 2 * node + 1, nums);
                int rSum = build(mid + 1, right, 2 * node + 2, nums);
                tree[node] = lSum + rSum;
            }
            return tree[node];
        }

        int query(int left, int right, int start, int end, int node = 0){
            if(left > end || right < start)
                return 0;
            if(start <= left && right <= end)
                return tree[node];
            int mid = (left + right) / 2;
            int lSum = query(left, mid, start, end, 2 * node + 1);
            int rSum = query(mid + 1, right, start, end, 2 * node + 2);
            return lSum + rSum;
        }

        void update(int left, int right, int index, int delta, int node = 0){
            if (left == right) {
                tree[node] += delta;
                return;
            }
            int mid = (left + right) / 2;
            if (index <= mid)
                update(left, mid, index, delta, 2 * node + 1);
            else
                update(mid + 1, right, index, delta, 2 * node + 2);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }

    };
public:
    SegmentTree* segTree;
    int size;
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr = nums;
        size = arr.size();
        segTree = new SegmentTree(nums);
    }
    
    void update(int index, int val) {
        int delta = val - arr[index];
        arr[index] = val;
        segTree->update(0, size - 1, index, delta);
    }
    
    int sumRange(int left, int right) {
        return segTree->query(0, size - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */