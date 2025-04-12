class Solution {
public:
    vector<int> sumZero(int n) {
        int half = n / 2;
        vector<int> ans;
        for (int i = 1; i <= half; i++)
            ans.push_back(i);
        for (int i = -half; i <= -1; i++)
            ans.push_back(i);
        if (n % 2)
            ans.push_back(0);
        return ans;
    }
};