class FoodRatings {
    struct Comparator {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            if (a.first == b.first) 
                return a.second < b.second;
            return a.first > b.first;
        }
    };
    
    unordered_map<string, set<pair<int, string>, Comparator>> cuisineToFoodRate;
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRate;
    
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            cuisineToFoodRate[cuisines[i]].insert({ratings[i], foods[i]});
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRate[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        auto& foodSet = cuisineToFoodRate[cuisine];
        foodSet.erase({foodToRate[food], food});
        foodSet.insert({newRating, food});
        foodToRate[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineToFoodRate[cuisine].begin()->second;
    }
};
