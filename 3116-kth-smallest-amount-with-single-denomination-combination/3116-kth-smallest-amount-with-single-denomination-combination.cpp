class Solution {
public:
    using ll = long long;

    ll gcd(ll a, ll b) {
        while (b) {
            ll temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    ll lcm(ll a, ll b) {
        return a / gcd(a, b) * b;
    }

    ll countAmounts(ll x, vector<int>& coins) {
        int n = coins.size();
        ll count = 0;

        for (int mask = 1; mask < (1 << n); ++mask) {
            ll multiple = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    ++bits;

                    multiple = lcm(multiple, (ll)coins[i]);

                    // LCM > x means this subset contributes 0.
                    if (multiple > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            ll contribution = x / multiple;

            if (bits % 2 == 1)
                count += contribution;
            else
                count -= contribution;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        // Remove coins whose multiples are already covered
        // by a smaller coin.
        sort(coins.begin(), coins.end());

        vector<int> filtered;

        for (int coin : coins) {
            bool redundant = false;

            for (int c : filtered) {
                if (coin % c == 0) {
                    redundant = true;
                    break;
                }
            }

            if (!redundant)
                filtered.push_back(coin);
        }

        coins = filtered;

        ll low = 1;
        ll high = (ll)coins[0] * k;

        while (low < high) {
            ll mid = low + (high - low) / 2;

            if (countAmounts(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};