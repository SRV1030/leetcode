class Solution {
public:
    int getMaxConsecutiveStreak(vector<int>& bars){
        sort(bars.begin(), bars.end());
        int streak = 1, result = 1;
        for(int index = 1; index < bars.size(); ++index){
            if(bars[index] - bars[index - 1] == 1)
                ++streak;
            else
                streak = 1;
            result = max(streak, result);
        }
        return result + 1;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int length =  min(getMaxConsecutiveStreak(hBars), getMaxConsecutiveStreak(vBars));
        return length * length;
    }
};