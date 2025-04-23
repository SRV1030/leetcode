class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> groups(n + 1);
        int maxGroup = 0, countMaxGroups = 0;
        for (int i = 1; i <= n; i++) {
            int x = i, group = 0;
            while (x) {
                group += x % 10;
                x /= 10;
            }
            groups[group]++;
            maxGroup = max(maxGroup, groups[group]);
        }
        for (auto& group : groups)
            countMaxGroups += (group == maxGroup);
        return countMaxGroups;
    }
};