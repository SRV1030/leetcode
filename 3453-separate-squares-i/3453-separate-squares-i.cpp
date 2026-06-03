class Solution {
public:
    double caluclateArea(vector<vector<int>>& squares, double y){
        double area = 0.0;
        for(auto& square : squares){
            double l = square[2], y0 = square[1] + l;
            if(y >= y0)
                continue;
            double h = min(l, y0 - y);
            area += h * l;
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double A = caluclateArea(squares, -1e9);
        double half = A / 2.0;
        double left = INT_MAX, right = INT_MIN;
        for(auto& square : squares){
            double len = square[1] + square[2];
            left = min(left, (double)square[1]);
            right = max(right, len);
        }
        double epsilion = 1e-5;
        while(right - left > epsilion){
            double mid = (left + right) / 2.0;
            double A0 = caluclateArea(squares, mid);
            if(half < A0)
                left = mid;
            else
                right = mid;
        }
        return left;
    }
};