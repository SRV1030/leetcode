class Solution {
public:
    class FenwickTree{
        int n;
        vector<long long> tree;
    public:
        FenwickTree(int _n){
            n = _n + 10;
            tree.resize(n+1);
        }

        void add(int i,long long val){
            i++;
            while(i<n){
                tree[i]+=val;
                i+=(i&(-i));
            }
        }

        long long query(int i){
            long long res = 0;
            i++;
            while(i>0){
                res+=tree[i];
                i-=(i&(-i));
            }
            return res;
        }

        long long query(int l,int r){
            return query(r) - query(l-1);
        }
        
    };
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long n = nums1.size(), answer = 0;
        vector<int>numIndexMap(n,0);
        FenwickTree fnTree(n);
        for(int i=0;i<n;i++)numIndexMap[nums1[i]]=i;
        for(auto&i:nums2){
            int ind = numIndexMap[i];
            long long left = fnTree.query(ind);
            long long total = fnTree.query(n-1);
            long long right = (n-1-ind) - (total - left);
            answer += left * right;
            fnTree.add(ind,1);
        }
        return answer;
    }
};