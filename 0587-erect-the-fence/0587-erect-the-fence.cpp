class Solution {
public:
    struct Point {
        int x, y;
        bool operator<(Point P) const {
            if (P.x == x)
                return y < P.y;
            return x < P.x;
        }
        bool operator==(Point P) const { return x == P.x && y == P.y; }
    };

    bool clockwise(Point a, Point b, Point c) {
        return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) > 0;
    }

    bool counterClockwise(Point a, Point b, Point c) {
        return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) < 0;
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n <= 2)
            return trees;
        vector<Point> treePoints(n);
        for (int i = 0; i < n; i++) {
            treePoints[i].x = trees[i][0];
            treePoints[i].y = trees[i][1];
        }
        sort(treePoints.begin(), treePoints.end());
        vector<Point> up, down;
        up.push_back(treePoints[0]);
        down.push_back(treePoints[0]);

        Point first = treePoints[0],last = treePoints[n-1];

        for(int i=1;i<treePoints.size();i++){
            if(i==treePoints.size()-1 || !counterClockwise(first,treePoints[i],last)) {
                while(up.size()>=2 && counterClockwise(up[up.size()-2],up.back(),treePoints[i])) up.pop_back();
                up.push_back(treePoints[i]);
            }
            if(i==treePoints.size()-1 || !clockwise(first,treePoints[i],last)){
                while(down.size()>=2 && clockwise(down[down.size()-2],down.back(),treePoints[i])) down.pop_back();
                down.push_back(treePoints[i]);
            } 
        }
        up.insert(up.end(), down.begin(), down.end());
        set<Point> st(up.begin(), up.end());
        vector<vector<int>> resTrees;
        for (auto& i : st)
            resTrees.push_back({i.x, i.y});
        return resTrees;
    }
};