class Solution {

    /*
        Fenwick Tree (Binary Indexed Tree)

        USE:
        - Maintains frequency of elements inside current window
        - Allows us to quickly answer:
              "how many numbers <= X are present?"
        - Needed for inversion counting in O(log N)
    */
    class FenwickTree{
        vector<int> tree;
        int n;

    public:
        // USE: initialize Fenwick tree with size = number of distinct values
        FenwickTree(int _n){
            n = _n;
            tree = vector<int>(n + 1, 0); // 1-indexed internally
        }

        /*
            USE:
            Add/remove frequency at given rank.

            val = +1 → insert element into window
            val = -1 → remove element from window
        */
        void update(int index, int val){
            ++index; // convert 0-index → 1-index
            for(; index <= n; index += (index & (-index)))
                tree[index] += val;
        }

        /*
            USE:
            Returns count of elements with rank <= index
            (prefix frequency sum)
        */
        int query(int index){
            ++index;
            int val = 0;
            for(; index > 0; index -= (index & (-index)))
                val += tree[index];
            return val;
        }

        /*
            USE:
            Count elements whose ranks lie in [left, right]
        */
        int query(int left, int right){
            if(left > right)
                return 0;
            return query(right) - (left ? query(left - 1) : 0);
        }
    };

public:

    /*
        USE:
        Coordinate compression mapping.

        Converts actual value → rank (0..distinct-1)

        Needed because:
        - nums values may be large (1e9)
        - Fenwick indices must be small & continuous
    */
    int getRank(vector<int>& nums, int x){
        return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
    }

    long long minInversionCount(vector<int>& nums, int k) {

        /*
            USE:
            Create sorted UNIQUE values for compression.
        */
        set<int> st(nums.begin(), nums.end());
        vector<int> sortedNums(st.begin(), st.end());

        int size = sortedNums.size();

        /*
            Fenwick stores:
                frequency of each rank inside window
        */
        FenwickTree fw(size);

        long long inv = 0;

        /*
        ------------------------------------------------
        BUILD FIRST WINDOW
        ------------------------------------------------

        For each element:
            inversions added =
                number of existing elements GREATER than it
        */
        for(int index = 0; index < k; ++index){

            int rank = getRank(sortedNums, nums[index]);

            // USE:
            // count elements already inserted that are greater
            inv += fw.query(rank + 1, size - 1);

            // insert current element into window
            fw.update(rank, 1);
        }

        long long ans = inv;

        /*
        ------------------------------------------------
        SLIDE WINDOW
        ------------------------------------------------
        Each move:
            1) remove outgoing element
            2) add incoming element
        Only pairs involving these elements change.
        */
        for(int index = k; index < nums.size(); ++index){

            /*
                REMOVE OUTGOING ELEMENT
            */
            int outRank = getRank(sortedNums, nums[index - k]);

            // remove from frequency structure
            fw.update(outRank, -1);

            /*
                USE:
                subtract inversions formed where outgoing
                element was the LEFT element.

                Count elements smaller than it.
            */
            inv -= fw.query(0, outRank - 1);


            /*
                ADD INCOMING ELEMENT
            */
            int inRank = getRank(sortedNums, nums[index]);

            /*
                USE:
                new inversions formed with elements
                already in window that are GREATER.
            */
            inv += fw.query(inRank + 1, size - 1);

            // insert incoming element
            fw.update(inRank, 1);

            // we need MINIMUM inversion window
            ans = min(ans, inv);
        }

        return ans;
    }
};