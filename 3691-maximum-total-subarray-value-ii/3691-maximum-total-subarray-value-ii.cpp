class Solution {
    class SegmentTree{
        class Node{
        public:
            int lo;
            int hi;
            int maxV;
            int minV;
            int lazy = 0;
            Node *left, *right;
            
            Node(int lo, int hi){
                this->lo = lo;
                this->hi = hi;
                maxV = INT_MIN;
                minV = INT_MAX;
                left = nullptr;
                right = nullptr;
            }
        };
        Node* root;
    public:
        SegmentTree(vector<int> &nums){
            root = build(nums, 0, nums.size() - 1);
        }

        Node* getRoot(){
            return root;
        }

        void pull(Node* node){
            node->maxV = max(node->left->maxV, node->right->maxV);
            node->minV = min(node->left->minV, node->right->minV);
        }

        void apply(Node* node, int delta) {
            node->maxV += delta;
            node->minV += delta;
            node->lazy += delta;
        }

        void push(Node* node){
            if(node->lazy == 0)
                return;
            if(node->left)
                apply(node->left, node->lazy);
            if(node->right)
                apply(node->right, node->lazy);
            node->lazy = 0;
        }

        Node* build(vector<int> &nums, int lo, int hi){
            Node* node = new Node(lo, hi);
            if(lo == hi){
                node->maxV = nums[lo];
                node->minV = nums[lo];
                return node;
            }
            int mid = (lo + hi) / 2;
            node->left = build(nums, lo , mid);
            node->right = build(nums, mid + 1 , hi);
            pull(node);
            return node;
        }

        void pointUpdate(int index, int val, Node* node){
            if(node->lo == node->hi){
                node->maxV = val;
                node->minV = val;
                return;
            }
            push(node);
            int mid = (node->lo + node->hi) / 2;
            if(index <= mid)
                pointUpdate(index, val, node->left);
            else
                pointUpdate(index, val, node->right);
            pull(node);
        }

        void rangeUpdate(int lo, int hi, int delta, Node* node){
            if(!node || node->hi < lo || node->lo > hi)
                return;
            if(lo <= node->lo && node->hi <= hi){
                apply(node, delta);
                return;
            }
            push(node);
            rangeUpdate(lo, hi, delta, node->left);
            rangeUpdate(lo, hi, delta, node->right);
            pull(node);
        }

        pair<int, int> query(int lo, int hi, Node* node){
            if(!node || node->hi < lo || node->lo > hi)
                return {INT_MAX, INT_MIN};

            if(lo <= node->lo && node->hi <= hi)
                return {node->minV, node->maxV};
            
            push(node);

            pair<int, int> leftVals = query(lo, hi, node->left);
            pair<int, int> rightVals = query(lo, hi, node->right);
            return {min(leftVals.first, rightVals.first), max(leftVals.second, rightVals.second)};
        }

        pair<int, int> query(int lo, int hi){
            return query(lo, hi, root);
        }
    };
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        SegmentTree sTree(nums);
        int size = nums.size();
        priority_queue<vector<int>> maxHeap;
        for(int lo = 0; lo < size; ++lo){
            int hi = size - 1;
            auto minMAx = sTree.query(lo, hi);
            maxHeap.push({minMAx.second - minMAx.first, lo, hi});
        }
        long long sum = 0;
        while(k--){
            auto state = maxHeap.top();
            maxHeap.pop();
            sum += state[0];
            int lo = state[1], hi = state[2] - 1;
            if(lo <= hi){
                auto minMAx = sTree.query(lo, hi);
                maxHeap.push({minMAx.second - minMAx.first, lo, hi});
            }
        }
        return sum;
    }
};