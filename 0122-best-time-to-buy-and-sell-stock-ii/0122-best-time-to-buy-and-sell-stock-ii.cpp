class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        
        return profit;        
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int numberOfDays = prices.size();
//         vector<vector<int>> memory(numberOfDays + 1, vector<int>(2));
//         for(int day = numberOfDays - 1; day >=0; day--){
//             for(int buyState = 0; buyState <=1; buyState++){
//                 memory[day][buyState] =  memory[day + 1][buyState];
//                 int sign = buyState?  1 : -1;
//                 memory[day][buyState] = max(memory[day][buyState], sign * prices[day] + memory[day + 1][!buyState]);
//             }
//         }
//         return memory[0][0];
//     }
// };




// class Solution {
//     int numberOfDays;
//     vector<vector<int>> memory;
// public:
//     int getMaxProfit(int day, bool boughtStatus, vector<int>& prices){
//         if(day == numberOfDays)
//             return 0;
//         int& profit = memory[day][boughtStatus];
//         if(profit == -1){
//             profit = getMaxProfit(day + 1, boughtStatus, prices);
//             if(boughtStatus == 0)
//                 profit = max(profit, - prices[day] + getMaxProfit(day + 1, 1, prices));
//             else
//                 profit = max(profit, + prices[day] + getMaxProfit(day + 1, 0, prices));
//         }
//         return profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         numberOfDays = prices.size();
//         memory = vector<vector<int>>(numberOfDays, vector<int>(2, -1));
//         return getMaxProfit(0, 0, prices);
//     }
// };