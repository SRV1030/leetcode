class Solution {
    int MAXSIZE = 1e5 + 5;
    vector<bool> prime;

    void init() {
        prime = vector<bool>(MAXSIZE, true);
        prime[0] = prime[1] = false;

        for (int num = 2; num * num < MAXSIZE; ++num) {
            if (prime[num]) {
                for (int nxt = num * num; nxt < MAXSIZE; nxt += num) {
                    prime[nxt] = false; // ✅ correct marking
                }
            }
        }
    }

public:
    int minOperations(vector<int>& nums) {
        init();

        int count = 0;

        for (int ind = 0; ind < nums.size(); ++ind) {
            int num = nums[ind];

            if (ind % 2) {
                while (num < MAXSIZE && prime[num]) {
                    ++count;
                    ++num;
                }
            } else {
                while (num < MAXSIZE && !prime[num]) {
                    ++count;
                    ++num;
                }
            }
        }

        return count;
    }
};