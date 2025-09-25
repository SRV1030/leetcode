class Solution {
public:
    int candy(vector<int>& ratings) {
        int children = ratings.size();
        vector<int> candies(children, 1);
        for(int child = 1; child < children; ++child){
            if(ratings[child - 1] < ratings[child])
                candies[child] = 1 + candies[child - 1];
        }
        int total = candies[children - 1];
        for(int child = children - 2; child >= 0; --child){
            if(ratings[child + 1] < ratings[child])
                candies[child] = max(candies[child], 1 + candies[child + 1]);
            total += candies[child];
        }
        return total;
    }
};