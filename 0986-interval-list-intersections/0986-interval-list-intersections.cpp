class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        for(int indF = 0, indS = 0; indF < firstList.size() && indS < secondList.size();){
            int xf = firstList[indF][0], yf = firstList[indF][1];
            int xs = secondList[indS][0], ys = secondList[indS][1];
            int overLapX = max(xf, xs), overLapY = min(yf, ys);
            if(overLapX <= overLapY)
                result.push_back({overLapX, overLapY});
            yf == overLapY ? ++indF : ++indS;
        }
        return result;
    }
};