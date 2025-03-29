class Solution {
public:

    const int mod = 1e9 + 7;
    int size;

    int primeScore(int x) {
        int c = 0;
        if(x%2==0){
            c++;
            while (x % 2 == 0) {
                x /= 2;
            }
        }
        for (int i = 3; i * i <= x; i += 2) {
            if(x%i==0){
                c++;
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        return c + (x > 2);
    }
    
    long long power(long long x, long long y) {
        long long res = 1;
        while (y) {
            if (y % 2)
                res = (res * x) % mod;
            x = (x * x) % mod;
            y >>= 1;
        }
        return res;
    }

    vector<int> greatestScoreLeft(vector<int> score) {
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < size; i++) {
            while (!st.empty() && score[i] > score[st.top()])
                st.pop();
            ans.push_back(st.empty() ? -1 : st.top());
            st.push(i);
        }
        return ans;
    }

    vector<int> greatestScoreRight(vector<int> score) {
        stack<int> st;
        vector<int> ans(size);
        for (int i = size - 1; i >= 0; i--) {
            while (!st.empty() && score[i] >= score[st.top()])
                st.pop();
            ans[i] = st.empty() ? size : st.top();
            st.push(i);
        }
        return ans;
    }

    int maximumScore(vector<int>& nums, int k) {
        size = nums.size();
        vector<int> score;

        for (auto& i : nums)
            score.push_back(primeScore(i));

        
        vector<int> left = greatestScoreLeft(score),
                    right = greatestScoreRight(score);
                    
        vector<vector<int>> maxHeap;
        for (int i = 0; i < size; i++)
            maxHeap.push_back({nums[i], i});

        sort(maxHeap.begin(), maxHeap.end(), greater<>());

        long long maxScore = 1;
        for (int i = 0; i < size && k>0; i++) {
            vector<int> top = maxHeap[i];
            long long num = top[0], index = top[1];
            long long operations =
                min((long long)k,
                    (long long)(right[index] - index) * (index - left[index]));
            maxScore = (maxScore * power(num, operations)) % mod;
            k -= operations;
        }
        return maxScore;
    }
};