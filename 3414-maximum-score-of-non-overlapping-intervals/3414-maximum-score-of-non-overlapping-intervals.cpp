class Solution {
    struct State {
        long long score = 0;
        array<int, 4> ids{};
        int len = 0;
    };

    int n;
    vector<array<int, 4>> a;
    vector<int> nxt;
    vector<vector<State>> memo;
    vector<vector<bool>> seen;

    bool better(const State& x, const State& y) {
        if (x.score != y.score)
            return x.score > y.score;

        for (int i = 0; i < min(x.len, y.len); i++) {
            if (x.ids[i] != y.ids[i])
                return x.ids[i] < y.ids[i];
        }

        return x.len < y.len;
    }

    State solve(int i, int cnt) {
        if (i == n || cnt == 4)
            return {};

        if (seen[i][cnt])
            return memo[i][cnt];

        seen[i][cnt] = true;

        // Skip
        State skip = solve(i + 1, cnt);

        // Take
        State take = solve(nxt[i], cnt + 1);
        take.score += a[i][2];

        // Insert original index while keeping ids sorted
        int id = a[i][3];
        int pos = take.len;

        while (pos > 0 && take.ids[pos - 1] > id) {
            take.ids[pos] = take.ids[pos - 1];
            pos--;
        }

        take.ids[pos] = id;
        take.len++;

        return memo[i][cnt] =
            better(take, skip) ? take : skip;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        a.resize(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            if (x[0] != y[0])
                return x[0] < y[0];

            if (x[1] != y[1])
                return x[1] < y[1];

            return x[3] < y[3];
        });

        // Precompute next[i]
        nxt.resize(n);

        for (int i = 0; i < n; i++) {
            int lo = i + 1;
            int hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][0] > a[i][1])
                    hi = mid;
                else
                    lo = mid + 1;
            }

            nxt[i] = lo;
        }

        memo.assign(n, vector<State>(5));
        seen.assign(n, vector<bool>(5, false));

        State ans = solve(0, 0);

        return vector<int>(ans.ids.begin(),
                           ans.ids.begin() + ans.len);
    }
};