class Solution {
    int n, K;

    const long long NEG = -(1LL << 60);

    vector<int> a;

    // memo[index][parts][state]
    vector<vector<vector<long long>>> memo;

    long long dfs(int index, int parts, int state) {

        if (index == n)
            return state == 0 ? 0 : NEG;

        long long &ans = memo[index][parts][state];

        if (ans != NEG)
            return ans;

        // Skip current element
        ans = dfs(index + 1, parts, state);

        int current = a[index];

        if (state == 0) {

            if (parts < K) {

                // current acts as maximum
                ans = max(
                    ans,
                    (long long)current +
                    dfs(index + 1, parts + 1, 1)
                );

                // current acts as minimum
                ans = max(
                    ans,
                    -(long long)current +
                    dfs(index + 1, parts + 1, 2)
                );
            }

        } else if (state == 1) {

            // Maximum was selected earlier.
            // current acts as minimum.
            ans = max(
                ans,
                -(long long)current +
                dfs(index + 1, parts, 0)
            );

        } else {

            // Minimum was selected earlier.
            // current acts as maximum.
            ans = max(
                ans,
                (long long)current +
                dfs(index + 1, parts, 0)
            );
        }

        return ans;
    }

public:

    long long maximumScore(vector<int>& nums, int k) {

        n = nums.size();

        K = min(k, n / 2);

        if (K == 0)
            return 0;

        // Find the global minimum
        int minIndex =
            min_element(nums.begin(), nums.end())
            - nums.begin();

        // Duplicate the array for circular handling
        vector<int> doubled = nums;

        doubled.insert(
            doubled.end(),
            nums.begin(),
            nums.end()
        );

        long long answer = 0;

        // Two possible rotations around the minimum
        vector<int> starts = {
            minIndex,
            (minIndex + 1) % n
        };

        for (int start : starts) {

            a.clear();

            // Build linear version of the circular array
            for (int i = 0; i < n; ++i) {
                a.push_back(doubled[start + i]);
            }

            // memo[index][parts][state]
            memo.assign(
                n + 1,
                vector<vector<long long>>(
                    K + 1,
                    vector<long long>(3, NEG)
                )
            );

            answer = max(
                answer,
                dfs(0, 0, 0)
            );
        }

        return answer;
    }
};