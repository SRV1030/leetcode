class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int total_container = n * n * w;
        return total_container < maxWeight ? n * n : maxWeight / w;
    }
};