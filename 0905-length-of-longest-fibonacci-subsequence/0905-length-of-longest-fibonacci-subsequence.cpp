class Solution {
   public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> avl;
        int len = arr.size();
        int ans = 0;
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                if (avl.find(arr[i] + arr[j]) != avl.end()) {
                    int cnt = 3, prev = arr[i], curr = arr[i] + arr[j];
                    while (avl.find(curr + prev) != avl.end()) {
                        int tmp = prev + curr;
                        cnt++, prev = curr, curr = tmp;
                    }
                    ans = max(ans, cnt);
                }
            }
            avl.insert(arr[i]);
        }
        return ans;
    }
};