class Solution {
public:

    static bool comparator(vector<int> &property1,vector<int> &property2){
        if(property1[0] == property2[0])
            return property1[1] > property2[1];
        return property1[0] < property2[0];
    }

    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comparator);
        int sizeOfProperties = properties.size();
        int maxDefence = INT_MIN;
        int weakCharacters = 0;
        for(int propertyIndex = sizeOfProperties - 1; propertyIndex >= 0; propertyIndex--){
            if(properties[propertyIndex][1] < maxDefence)
                weakCharacters++;
            maxDefence = max(maxDefence, properties[propertyIndex][1]);
        }
        return weakCharacters;
    }
};