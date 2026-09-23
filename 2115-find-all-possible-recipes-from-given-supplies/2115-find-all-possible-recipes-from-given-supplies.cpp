class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> allRecepies;
        unordered_map<string,int> inDegree;
        unordered_map<string, vector<string>> ingridientsToRecepies;
        int recipesSize = recipes.size();
        for(int index = 0; index < recipesSize; index++){
            string recipe = recipes[index];
            inDegree[recipe] = ingredients[index].size();
            for(auto& ingredient: ingredients[index])
                ingridientsToRecepies[ingredient].push_back(recipe);
        }

        queue<string> bfsQueue(supplies.begin(),supplies.end());
        while(!bfsQueue.empty()){
            string item = bfsQueue.front();
            bfsQueue.pop();
            if(!ingridientsToRecepies.count(item)) continue;
            for(auto& recipe: ingridientsToRecepies[item]){
                inDegree[recipe]--;
                if(inDegree[recipe] == 0){
                    allRecepies.push_back(recipe);
                    bfsQueue.push(recipe);
                }
            }
        }
        return allRecepies;
    }
};