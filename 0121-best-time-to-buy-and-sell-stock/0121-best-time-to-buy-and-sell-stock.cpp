class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0], profit = 0;
        for(auto& price: prices){
            if(price < minPrice)
                minPrice = price;
            else
                profit = max(profit, price - minPrice);
        }
        return profit;
    }
};