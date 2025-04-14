class Solution {
public:
    int findClosest(int x, int y, int z) {
        int p1_distance = abs(x-z),p2_distance = abs(y-z);
        return p1_distance<p2_distance?1:p1_distance==p2_distance?0:2;
    }
};