class Solution {
public:
    int nextGreaterElement(int n) {
        if (n == INT_MAX)
            return -1;
        string s = to_string(n);
        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i] < s[i + 1]) {
                int j = s.size() - 1;
                while (j > i && s[i] >= s[j])
                    j--;
                swap(s[i], s[j]);
                reverse(s.begin() + i + 1, s.end());
                long long val = stoll(s);
                if (val > INT_MAX)
                    return -1;
                return val;
            }
        }
        return -1;
    }
};